/************************************************************/
/*    NAME: Toya Takahashi                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: ParseWaypoint.cpp                                        */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "ParseWaypoint.h"

using namespace std;

//---------------------------------------------------------
// Constructor()

ParseWaypoint::ParseWaypoint()
{
}

//---------------------------------------------------------
// Destructor

ParseWaypoint::~ParseWaypoint()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail()

bool ParseWaypoint::OnNewMail(MOOSMSG_LIST &NewMail)
{
    AppCastingMOOSApp::OnNewMail(NewMail);

    MOOSMSG_LIST::iterator p;
    for(p=NewMail.begin(); p!=NewMail.end(); p++) {
        CMOOSMsg &msg = *p;
        string key    = msg.GetKey();
        string sval  = msg.GetString(); 

#if 0 // Keep these around just for template
        string comm  = msg.GetCommunity();
        double dval  = msg.GetDouble();
        string sval  = msg.GetString(); 
        string msrc  = msg.GetSource();
        double mtime = msg.GetTime();
        bool   mdbl  = msg.IsDouble();
        bool   mstr  = msg.IsString();
#endif

        if (key == "WPT_UPDATE_GPS") 
            handleNodeReport(sval);

        else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
            reportRunWarning("Unhandled Mail: " + key);
    }

    return(true);
}

//---------------------------------------------------------
// Procedure: handleNodeReport()

void ParseWaypoint::handleNodeReport(string report) {
    m_last_rcvd = report;

    vector<string> wpt_vec = parseString(report, ':');
    string new_msg = "points=";
    for (int i = 0; i < wpt_vec.size(); i++) {
        vector<string> latlon_vec = parseString(wpt_vec[i], ',');
        double wpt_x, wpt_y;
        m_Geodesy.LatLong2LocalUTM(stod(latlon_vec[0]), stod(latlon_vec[1]), wpt_y, wpt_x);
        new_msg += to_string(wpt_x) + "," + to_string(wpt_y);
        if (i < wpt_vec.size() - 1)
            new_msg += ":";
    }
    m_new_msg = new_msg;
}

//---------------------------------------------------------
// Procedure: OnConnectToServer()

bool ParseWaypoint::OnConnectToServer()
{
    registerVariables();
    return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool ParseWaypoint::Iterate()
{
    AppCastingMOOSApp::Iterate();

    Notify("WPT_UPDATE", m_new_msg);

    AppCastingMOOSApp::PostReport();
    return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool ParseWaypoint::OnStartUp()
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

    geodesySetup();
    registerVariables();	
    return(true);
}

//---------------------------------------------------------
// Procedure: geodesySetup()

void ParseWaypoint::geodesySetup() {
    // Get Latitude Origin from .MOOS Mission File
    bool latOK = m_MissionReader.GetValue("LatOrigin", m_lat_origin);
    if(!latOK)
        reportConfigWarning("Latitude origin missing in MOOS file.");

    // Get Longitude Origin from .MOOS Mission File
    bool lonOK = m_MissionReader.GetValue("LongOrigin", m_lon_origin);
    if(!lonOK)
        reportConfigWarning("Longitude origin missing in MOOS file.");

    // Initialise CMOOSGeodesy object
    bool geoOK = m_Geodesy.Initialise(m_lat_origin, m_lon_origin);
    if(!geoOK)
        reportConfigWarning("Geodesy::Initialise() failed. Invalid origin.");
}

//---------------------------------------------------------
// Procedure: registerVariables()

void ParseWaypoint::registerVariables()
{
    AppCastingMOOSApp::RegisterVariables();
    Register("WPT_UPDATE_GPS", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool ParseWaypoint::buildReport() 
{
    m_msgs << "============================================" << endl;
    m_msgs << "File: ParseWaypoint.cpp                     " << endl;
    m_msgs << "============================================" << endl;

    ACTable actab(2);
    actab << "last received msg: " << m_last_rcvd;
    m_msgs << actab.getFormattedString();

    return(true);
}




