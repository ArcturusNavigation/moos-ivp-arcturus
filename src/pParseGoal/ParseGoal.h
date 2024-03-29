/************************************************************/
/*    NAME: Christian and Janelle                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: ParseGoal.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef ParseGoal_HEADER
#define ParseGoal_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"

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

 private: // Configuration variables

 private: // State variables
};

#endif 
