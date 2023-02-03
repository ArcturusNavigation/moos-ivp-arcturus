/************************************************************/
/*    NAME: Toya Takahashi                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: Odometry.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef Odometry_HEADER
#define Odometry_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

// inherits from AppCastingMOOSApp class to enable AppCasting
class Odometry : public AppCastingMOOSApp
{
 public:
   Odometry();
   ~Odometry();

 protected: // Standard MOOSApp functions being overloaded 
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();
   bool buildReport();

 protected: // App-specific functions / parameters
   void RegisterVariables();           // Registers variables published to the community
   bool m_first_reading;               // Variable for differentiating between first run and the following iterations

   // Variables relating to the position and distance travelled by the vessel
   double m_current_x;
   double m_current_y;
   double m_previous_x;
   double m_previous_y;
   double m_total_distance;

   std::string m_total_distance_name;  // Holds the key of the MOOS variable, defined to hold total distance (in the configuration file)
};

#endif
