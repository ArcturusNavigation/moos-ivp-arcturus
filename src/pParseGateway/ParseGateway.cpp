/************************************************************/
/*    NAME: Toya Takahashi                                  */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: ParseGateway.cpp                                */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "ParseGateway.h"

using namespace std;

//---------------------------------------------------------
// Constructor()

ParseGateway::ParseGateway()
{
}

//---------------------------------------------------------
// Destructor

ParseGateway::~ParseGateway()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail()

bool ParseGateway::OnNewMail(MOOSMSG_LIST &NewMail)
{
    AppCastingMOOSApp::OnNewMail(NewMail);

    MOOSMSG_LIST::iterator p;
    for(p=NewMail.begin(); p!=NewMail.end(); p++) {
        CMOOSMsg &msg = *p;
        string key  = msg.GetKey();
        string sval = msg.GetString(); 

#if 0 // Keep these around just for template
        string comm  = msg.GetCommunity();
        double dval  = msg.GetDouble();
        string sval  = msg.GetString(); 
        string msrc  = msg.GetSource();
        double mtime = msg.GetTime();
        bool   mdbl  = msg.IsDouble();
        bool   mstr  = msg.IsString();
#endif

        if (key == "NAV_REPORT") 
            handleNavReport(sval);
            
        else if (key == "WPT_UPDATE_GPS") 
            handleWptReport(sval);

        else if (key != "APPCAST_REQ")
            reportRunWarning("Unhandled Mail: " + key);
    }

    return(true);
}

//---------------------------------------------------------
// Procedure: handleNavReport()

void ParseGateway::handleNavReport(string report) {
    m_last_rcvd = report;
    
    m_nav_heading = stod(tokStringParse(report, "NAV_HEADING", ',', '='));
    m_nav_lat     = stod(tokStringParse(report, "NAV_LAT", ',', '='));
    m_nav_lon     = stod(tokStringParse(report, "NAV_LON", ',', '='));
    m_nav_speed   = stod(tokStringParse(report, "NAV_SPEED", ',', '='));
}

//---------------------------------------------------------
// Procedure: handleWptReport()

void ParseGateway::handleWptReport(string report) {
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
    m_wpt_msg = new_msg;
}

//---------------------------------------------------------
// Procedure: OnConnectToServer()

bool ParseGateway::OnConnectToServer()
{
    registerVariables();
    return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool ParseGateway::Iterate()
{
    AppCastingMOOSApp::Iterate();

    m_Geodesy.LatLong2LocalUTM(m_nav_lat, m_nav_lon, m_nav_y, m_nav_x);

    Notify("NAV_LAT", m_nav_lat);
    Notify("NAV_LON", m_nav_lon);
    Notify("NAV_HEADING", m_nav_heading);
    Notify("NAV_SPEED", m_nav_speed);
    Notify("NAV_X", m_nav_x);
    Notify("NAV_Y", m_nav_y);
    Notify("WPT_UPDATE", m_wpt_msg);

    AppCastingMOOSApp::PostReport();
    return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool ParseGateway::OnStartUp()
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

void ParseGateway::geodesySetup() {
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

void ParseGateway::registerVariables()
{
    AppCastingMOOSApp::RegisterVariables();
    Register("NAV_REPORT", 0);
    Register("WPT_UPDATE_GPS", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool ParseGateway::buildReport() 
{
    m_msgs << "============================================" << endl;
    m_msgs << "File: ParseGateway.cpp                      " << endl;
    m_msgs << "============================================" << endl;

    ACTable actab(2);
    actab << "last received msg: " << m_last_rcvd;
    actab << "lat: "   << to_string(m_nav_lat);
    actab << "lon: "   << to_string(m_nav_lon);
    actab << "nav_x: " << to_string(m_nav_x);
    actab << "nav_y: " << to_string(m_nav_y);
    m_msgs << actab.getFormattedString();

    return(true);
}
