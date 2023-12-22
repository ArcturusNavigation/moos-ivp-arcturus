/************************************************************/
/*    NAME:                                               */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: GazeboVessel.cpp                                        */
/*    DATE: 2023-10-17                             */                                                   
/*    NOTE: Application to control simulated vessel in Gazebo */                                        
/*          Based on the iM300 application (Tyler Paine) 
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "GazeboVessel.h"

using namespace std;

//---------------------------------------------------------
// Constructor()

GazeboVessel::GazeboVessel()
{
  // Configuration variables (overwritten by .moos params)
  m_max_rudder = 30.0;     // default MAX_RUDDER (+/-)
  m_max_thrust = 100.0;    // default MAX_THRUST (+/-)
  m_drive_mode = "normal"; // default DRIVE_MODE ("normal"|"aggro"|"rotate"|"direct")

  m_nav_x = -1;
  m_nav_y = -1;
  m_nav_hdg = -1;
  m_nav_spd = -1;
    
}

//---------------------------------------------------------
// Destructor

GazeboVessel::~GazeboVessel()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail()

bool GazeboVessel::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key    = msg.GetKey();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    double mtime = msg.GetTime();

#if 0 // Keep these around just for template
    string comm  = msg.GetCommunity();
    string msrc  = msg.GetSource();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif

    if(key == "DESIRED_RUDDER") {
      if(m_thrust.getDriveMode() != "direct" ) {
	m_thrust.setRudder(dval);
      }
    }

    else if(key == "DESIRED_THRUST") {
      if(m_thrust.getDriveMode() != "direct" ) {
	m_thrust.setThrust(dval);
      }
    }

    else if(key == "NAV_SPEED") {
      m_nav_spd = dval;
    }

    else if(key == "NAV_HEADING") {
      m_nav_hdg = dval;
    }

    else if(key == "NAV_X") {
      m_nav_x = dval;
    }

    else if(key == "NAV_Y") {
      m_nav_y = dval;
    }

    else if(key == "ROTATE_HDG_TARGET") {
      m_rot_ctrl.setHeadingTarget(dval);
    }
    
    else if(key == "ROTATE_IN_PLACE") {
      bool bval, ok1;
      ok1 = setBooleanOnString(bval, sval);
      m_rot_ctrl.setRotateInPlace(bval);

      if(ok1 && bval) {
	m_rot_ctrl.setStartRotX(m_nav_x);
	m_rot_ctrl.setStartRotY(m_nav_y);
	m_rot_ctrl.setCmdTimeStamp(mtime);
      }
    }

    else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer()

bool GazeboVessel::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool GazeboVessel::Iterate()
{
  AppCastingMOOSApp::Iterate();

  // Part 1: Check for allstop or staleness

  // Part 2: Calculate Thrust L/R
  calculateThrust();

  //
  AppCastingMOOSApp::PostReport();
  return(true);
}

//----------------------------------------------------------
// Procedure: calculateThrust()
//

void GazeboVessel::calculateThrust()
{
  double thrust_l = 0.0;
  double thrust_r = 0.0;

  // Mode 1: Rotation
  // Check if OK to rotate in place
  bool ok_to_rotate = m_rot_ctrl.checkClearToRotate(m_nav_x, m_nav_y, m_curr_time);

  if (ok_to_rotate) {
    // overwrite incoming thrust and rudder commands
    double thrust, rudder;
    m_rot_ctrl.calControl(m_nav_hdg, m_nav_x, m_nav_y, thrust, rudder);

    // check if finished

    m_thrust.setRudder(rudder * m_max_rudder);
    m_thrust.setThrust(thrust);

    // use rotate mode for thrusters
    m_thrust.setDriveMode("rotate");

    // Check if finished
    if(m_rot_ctrl.getRotateInPlace() ) {
      ok_to_rotate = false;
    }
  } else {
    
    // Mode 2: Drive
    m_thrust.setDriveMode(m_drive_mode);
  }

  // Calculate L/R thruster values based on current DRIVE_MODE
  m_thrust.calcDiffThrust();
  // Update differential thrust values
  thrust_l = m_thrust.getThrustLeft();
  thrust_r = m_thrust.getThrustRight();

  Notify("COMMANDED_THRUST_L", thrust_l);
  Notify("COMMANDED_THRUST_R", thrust_r);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool GazeboVessel::OnStartUp()
{
  AppCastingMOOSApp::OnStartUp();

  STRING_LIST sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(!m_MissionReader.GetConfiguration(GetAppName(), sParams))
    reportConfigWarning("No config block found for " + GetAppName());

  STRING_LIST::iterator p;
  for(p=sParams.begin(); p!=sParams.end(); p++) {
    string orig  = *p;
    string line  = *p;
    string param = tolower(biteStringX(line, '='));
    string value = line;

    bool handled = false;
    if(param == "max_rudder") {
      handled = m_thrust.setMaxRudder(value);
      setDoubleOnString(m_max_rudder, value);
    }
    else if(param == "min_thrust") {
      handled = m_thrust.setMinThrust(value);
    }
    else if(param == "max_thrust") {
      handled = m_thrust.setMaxThrust(value);
      setDoubleOnString(m_max_thrust, value);
    }

    else if(param == "drive_mode") {
      handled = m_thrust.setDriveMode(value);
      m_drive_mode = value;
    }
    else if(param == "rfactor") {
      handled = m_thrust.setRFactor(value);
    }

    if(!handled)
      reportUnhandledConfigWarning(orig);

  }

  GeodesySetup();
  registerVariables();	
  return(true);
}

//--------------------------------------------------------                                              
// Procedure: GeodesySetup()                                                                            
bool GazeboVessel::GeodesySetup()                                                                       
{

  m_LatOrigin = 0.0;
  m_LonOrigin = 0.0;
  
  // Get Latitude Origin from .MOOS Mission File                                                        
  bool latOK = m_MissionReader.GetValue("LatOrigin", m_LatOrigin);                                      
  if(!latOK) {                                                                                          
    reportConfigWarning("Latitude origin missing in MOOS file.");                                       
    return(false);                                                                                      
  }                                                                                                     
                                                                                                        
  // Get Longitude Origin from .MOOS Mission File                                                       
  bool lonOK = m_MissionReader.GetValue("LongOrigin", m_LonOrigin);                                     
  if(!lonOK){                                                                                           
    reportConfigWarning("Longitude origin missing in MOOS file.");                                      
    return(false);                                                                                      
  }                                                                                                     
                                                                                                        
  // Initialise CMOOSGeodesy object                                                                     
  bool geoOK = m_geodesy.Initialise(m_LatOrigin, m_LonOrigin);                                          
  if(!geoOK) {                                                                                          
    reportConfigWarning("Geodesy::Initialise() failed. Invalid origin.");                               
    return(false);                                                                                      
  }                                                                                                     
                                                                                                        
  return(true);                                                                                         
}

//---------------------------------------------------------
// Procedure: registerVariables()

void GazeboVessel::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  //Register("IVPHELM_ALLSTOP", 0);
  //Register("MOOS_MANUAL_OVERRIDE", 0);
  Register("DESIRED_THRUST", 0);
  Register("DESIRED_RUDDER", 0);
  Register("ROTATE_IN_PLACE", 0);
  Register("ROTATE_HDG_TARGET", 0);
  Register("NAV_X", 0);
  Register("NAV_Y", 0);
  Register("NAV_HEADING", 0);
  Register("NAV_SPEED", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()
//                                                                                                    
// -------------------------------------------                                         
// Config:   max_r/t: 30/100      stale_check:  false                              
//           dr_mode: normal      stale_thresh: 15                         
// -------------------------------------------                                          
// Drive     des_rud: -30         des_thrust_L: 0
// State:    des_thr: 40          des_thrust_R: 0                                                
// -------------------------------------------                                      
// Nav:      nav_x: 5968          nav_hdg: 0                                                      
//           nav_y: -6616.3       nav_spd: 0.5  

bool GazeboVessel::buildReport() 
{

  string str_max_rud  = doubleToStringX(m_max_rudder,1);                             
  string str_max_thr  = doubleToStringX(m_max_thrust,1);                                     
  string str_max_both = str_max_rud + "/" + str_max_thr;                                 
  string str_des_rud  = doubleToStringX(m_thrust.getRudder(),1);                            
  string str_des_thr  = doubleToStringX(m_thrust.getThrust(),1);                           
  string str_des_thrL = doubleToStringX(m_thrust.getThrustLeft(),1);                          
  string str_des_thrR = doubleToStringX(m_thrust.getThrustRight(),1);                     
  string str_rot_hdg_tgt = doubleToStringX(m_rot_ctrl.getHeadingTarget(), 1);          
                                                                         
  string smin_th = doubleToStringX(m_thrust.getMinThrust());                        
  string smax_th = doubleToStringX(m_thrust.getMaxThrust());

  string str_sta_thr  = doubleToStringX(-1,1);                        
  string str_sta_ena  = boolToString(false); 

  string str_nav_x   = doubleToStringX(m_nav_x,1);                                  
  string str_nav_y   = doubleToStringX(m_nav_y,1);                                        
  string str_nav_hdg = doubleToStringX(m_nav_hdg,1);                                        
  string str_nav_spd = doubleToStringX(m_nav_spd,1);

  string pd_ruth = padString(str_max_both, 10, false);                                 
  string pd_drmo = padString(m_drive_mode, 10, false);                                    
  string pd_drud = padString(str_des_rud, 10, false);                                    
  string pd_dthr = padString(str_des_thr, 10, false);                                    
  string pd_navx = padString(str_nav_x, 10, false);                                 
  string pd_navy = padString(str_nav_y, 10, false);
  
  m_msgs << "Config:    max_r/t: " << pd_ruth << "   stale_check:  " << str_sta_ena << endl;            
  m_msgs << "           dr_mode: " << pd_drmo << "   stale_thresh: " << str_sta_thr << endl;      
  m_msgs << "           min_thr: " << smin_th << "   max_thr: " << smax_th << endl;              
  m_msgs << "------------------------------------------------------" << endl;                  
  m_msgs << "Drive:     des_rud: " << pd_drud << "   des_thrust_L: " << str_des_thrL << endl;  
  m_msgs << "State:     des_thr: " << pd_dthr << "   des_thrust_R: " << str_des_thrR << endl; 
  m_msgs << "------------------------------------------------------" << endl;              
  m_msgs << "Nav:       nav_x:   " << pd_navx << "   nav_hdg: " << str_nav_hdg << endl;             
  m_msgs << "           nav_y:   " << pd_navy << "   nav_spd: " << str_nav_spd << endl;
  m_msgs << "------------------------------------------------------" << endl;

  if ( m_rot_ctrl.getRotateInPlace() ) {                                                     
    m_msgs << "Rotation target heading: " << str_rot_hdg_tgt << endl;                               
    if ( m_rot_ctrl.checkClearToRotate( m_nav_x, m_nav_y, m_curr_time ) )            
      m_msgs << "All clear to rotate.                                " << endl;     
    m_msgs << "------------------------------------------------------" << endl;                
  }

  return(true);
}




