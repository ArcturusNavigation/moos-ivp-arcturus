/************************************************************/
/*    NAME: Christian and Janelle                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: ParseGoal.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef ParseGoal_HEADER
#define ParseGoal_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include "MOOS/libMOOSGeodesy/MOOSGeodesy.h"

class ParseGoal : public AppCastingMOOSApp
{
 public:
   ParseGoal();
   ~ParseGoal();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();
   void handleNodeReport(std::string report);
   void geodesySetup();

 private: // Configuration variables
  double m_goal_lat;
  double m_goal_lon;
  double m_goal_heading;
  double m_goal_x;
  double m_goal_y;
  double m_lat_origin;
  double m_lon_origin;
  std::string m_last_rcvd;

  CMOOSGeodesy m_Geodesy;
  

 private: // State variables
};

#endif 
