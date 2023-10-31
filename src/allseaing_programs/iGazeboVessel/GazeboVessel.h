/************************************************************/
/*    NAME: Michael DeFilippo                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: GazeboVessel.h                                          */
/*    DATE: 2023-10-17                             */
/*    NOTE: Application to control simulated vessel in Gazebo */
/*          Based on the iM300 application (Tyler Paine)
/************************************************************/

#ifndef GazeboVessel_HEADER
#define GazeboVessel_HEADER

#include <string>
#include "Thruster.h"
#include "VehRotController.h"
#include "MOOS/libMOOSGeodesy/MOOSGeodesy.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class GazeboVessel : public AppCastingMOOSApp
{
public:
  GazeboVessel();
  ~GazeboVessel();
  
protected: // Standard MOOSApp functions to overload  
  bool OnNewMail(MOOSMSG_LIST &NewMail);
  bool Iterate();
  bool OnConnectToServer();
  bool OnStartUp();
  
protected: // Standard AppCastingMOOSApp function to overload 
  bool buildReport();
  void registerVariables();
  
protected: // App Specific Functions
  bool GeodesySetup();
  void calculateThrust();
  
  
private: // Configuration variables
  double m_max_rudder;          // MAX_RUDDER
  double m_max_thrust;          // MAX_THRUST
  std::string m_drive_mode;     // DRIVE_MODE
  
private: // State variables
  CMOOSGeodesy m_geodesy;
  double m_LatOrigin;
  double m_LonOrigin;

  Thruster m_thrust;
  VehRotController m_rot_ctrl;

  double m_nav_x;
  double m_nav_y;
  double m_nav_hdg;
  double m_nav_spd;
};

#endif 
