/************************************************************/
/*    NAME: Christian and Janelle                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: ParseGoal.cpp                                        */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "ParseGoal.h"

using namespace std;

//---------------------------------------------------------
// Constructor()

ParseGoal::ParseGoal()
{
}

//---------------------------------------------------------
// Destructor

ParseGoal::~ParseGoal()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail()

bool ParseGoal::OnNewMail(MOOSMSG_LIST &NewMail)
{
  AppCastingMOOSApp::OnNewMail(NewMail);

  MOOSMSG_LIST::iterator p;
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;
    string key    = msg.GetKey();
    string sval   = msg.GetString();

#if 0 // Keep these around just for template
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif

     if(key == "ROS_REPORT_GOAL") 
       handleNodeReport(sval);

     else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
   }
	
   return(true);
}

void ParseGoal::handleNodeReport(string report) {
  m_last_rcvd = report;

  m_goal_lat = stod(tokStringParse(report, "GOAL_LAT", ',', '='));
  m_goal_lon = stod(tokStringParse(report, "GOAL_LON", ',', '='));
  m_goal_heading = stod(tokStringParse(report, "GOAL_HEADING", ',', '='));
}

//---------------------------------------------------------
// Procedure: OnConnectToServer()

bool ParseGoal::OnConnectToServer()
{
   registerVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool ParseGoal::Iterate()
{
  AppCastingMOOSApp::Iterate();

  m_Geodesy.LatLong2LocalUTM()

  Notify("GOAL_LAT", m_goal_lat);
  Notify("GOAL_LON", m_goal_lon);
  Notify("GOAL_HEADING", m_goal_heading);

  AppCastingMOOSApp::PostReport();
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool ParseGoal::OnStartUp()
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
    if(param == "foo") {
      handled = true;
    }
    else if(param == "bar") {
      handled = true;
    }

    if(!handled)
      reportUnhandledConfigWarning(orig);

  }
  
  registerVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: registerVariables()

void ParseGoal::registerVariables()
{
  AppCastingMOOSApp::RegisterVariables();
  Register("ROS_REPORT_GOAL", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool ParseGoal::buildReport() 
{
  m_msgs << "============================================" << endl;
  m_msgs << "File:                                       " << endl;
  m_msgs << "============================================" << endl;

  ACTable actab(4);
  actab << "Alpha | Bravo | Charlie | Delta";
  actab.addHeaderLines();
  actab << "one" << "two" << "three" << "four";
  m_msgs << actab.getFormattedString();

  return(true);
}



