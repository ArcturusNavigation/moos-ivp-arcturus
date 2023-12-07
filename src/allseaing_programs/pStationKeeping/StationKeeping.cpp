/************************************************************/
/*    NAME: Christian and Janelle                           */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: StationKeeping.cpp                              */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "StationKeeping.h"

using namespace std;

//---------------------------------------------------------
// Constructor()

StationKeeping::StationKeeping()
{
	m_first_reading = true;
	m_current_x = 0;
	m_current_y = 0;
	m_goal_x = 0;
	m_goal_y = 0;
}

//---------------------------------------------------------
// Destructor

StationKeeping::~StationKeeping()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail()

bool StationKeeping::OnNewMail(MOOSMSG_LIST &NewMail)
{
	AppCastingMOOSApp::OnNewMail(NewMail);

	MOOSMSG_LIST::iterator p;
	for(p=NewMail.begin(); p!=NewMail.end(); p++) {
		CMOOSMsg &msg = *p;
		string key    = msg.GetKey();

#if 0 // Keep these around just for template
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif

	if(key == "NAV_X") 
		m_current_x = msg.GetDouble();
    else if (key == "NAV_Y")
		m_current_y = msg.GetDouble();
	else if (key == "GOAL_X")
		m_goal_x = msg.GetDouble();
	else if (key == "GOAL_Y")
		m_goal_y = msg.GetDouble();

    else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
       reportRunWarning("Unhandled Mail: " + key);
    }

   return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer()

bool StationKeeping::OnConnectToServer()
{
	registerVariables();
	return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool StationKeeping::Iterate()
{
	AppCastingMOOSApp::Iterate();
	// NEED TO ADJUST P!!!
	double p = 1;

	double diff_x = m_goal_x - m_current_x;
	double diff_y = m_goal_y - m_current_y;

	double vel_x = diff_x * p;
	double vel_y = diff_y * p;

	Notify("VEL_X", vel_x);
	Notify("VEL_Y", vel_y);

	AppCastingMOOSApp::PostReport();
	return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool StationKeeping::OnStartUp()
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

void StationKeeping::registerVariables()
{
	AppCastingMOOSApp::RegisterVariables();
	Register("NAX_X", 0);
	Register("NAX_Y", 0);
	Register("GOAL_X", 0);
	Register("GOAL_Y", 0);

}


//------------------------------------------------------------
// Procedure: buildReport()

bool StationKeeping::buildReport() 
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




