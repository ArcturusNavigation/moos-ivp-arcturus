/************************************************************/
/*    NAME: Christian and Janelle                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: StationKeeping.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef StationKeeping_HEADER
#define StationKeeping_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

class StationKeeping : public AppCastingMOOSApp
{
 public:
   StationKeeping();
   ~StationKeeping();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected: // Standard AppCastingMOOSApp function to overload 
   bool buildReport();

 protected:
   void registerVariables();

 private: // Configuration variables
   bool   m_first_reading;
   double m_current_x;
   double m_current_y;
   double m_goal_x;
   double m_goal_y;

 private: // State variables
};

#endif 
