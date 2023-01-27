/************************************************************/
/*    NAME: Toya                                              */
/*    ORGN: MIT                                             */
/*    FILE: Sequence.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef Sequence_HEADER
#define Sequence_HEADER

#include "MOOS/libMOOS/MOOSLib.h"

class Sequence : public CMOOSApp
{
 public:
   Sequence();
   ~Sequence();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected:
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
};

#endif 
