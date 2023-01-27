/************************************************************/
/*    NAME: Toya                                              */
/*    ORGN: MIT                                             */
/*    FILE: Sequence.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "Sequence.h"

using namespace std;

//---------------------------------------------------------
// Constructor

Sequence::Sequence()
{
}

//---------------------------------------------------------
// Destructor

Sequence::~Sequence()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool Sequence::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) {
    CMOOSMsg &msg = *p;

#if 0 // Keep these around just for template
    string key   = msg.GetKey();
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif
   }
	
   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool Sequence::OnConnectToServer()
{
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool Sequence::Iterate()
{
  return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool Sequence::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string line  = *p;
      string param = tolower(biteStringX(line, '='));
      string value = line;
      
      if(param == "foo") {
        //handled
      }
      else if(param == "bar") {
        //handled
      }
    }
  }
  
  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void Sequence::RegisterVariables()
{
  // Register("FOOBAR", 0);
}

