/************************************************************/
/*    NAME: Toya Takahashi                                  */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: CircleAnimal.cpp                                */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "ACTable.h"
#include "CircleAnimal.h"

using namespace std;

//---------------------------------------------------------
// Constructor()

CircleAnimal::CircleAnimal()
{
}

//---------------------------------------------------------
// Destructor

CircleAnimal::~CircleAnimal()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail()

bool CircleAnimal::OnNewMail(MOOSMSG_LIST &NewMail)
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

        if(key == "ANIMAL_GPS") 
            handleNodeReport(sval);

        else if(key != "APPCAST_REQ") // handled by AppCastingMOOSApp
            reportRunWarning("Unhandled Mail: " + key);
    }

    return(true);
}

//---------------------------------------------------------
// Procedure: handleNodeReport()

void CircleAnimal::handleNodeReport(string report) {
    m_last_rcvd = report;

    int id = stoi(tokStringParse(report, "id", ',', '='));
    string animal = tokStringParse(report, "animal", ',', '=');
    double lat = stod(tokStringParse(report, "lat", ',', '='));
    double lon = stod(tokStringParse(report, "lon", ',', '='));
    double center_x, center_y;
    m_Geodesy.LatLong2LocalUTM(lat, lon, center_y, center_x);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer()

bool CircleAnimal::OnConnectToServer()
{
    registerVariables();
    return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool CircleAnimal::Iterate()
{
    AppCastingMOOSApp::Iterate();

    Notify("ANIMAL1_UPDATE", m_animal1_msg);
    Notify("ANIMAL2_UPDATE", m_animal2_msg);

    AppCastingMOOSApp::PostReport();
    return(true);
}

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool CircleAnimal::OnStartUp()
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

void CircleAnimal::geodesySetup() {
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

void CircleAnimal::registerVariables()
{
    AppCastingMOOSApp::RegisterVariables();
    Register("ANIMAL_GPS", 0);
    Register("CIRCLING", 0);
}


//------------------------------------------------------------
// Procedure: buildReport()

bool CircleAnimal::buildReport() 
{
    m_msgs << "============================================" << endl;
    m_msgs << "File: CircleAnimal.cpp                      " << endl;
    m_msgs << "============================================" << endl;

    ACTable actab(2);
    actab << "last received msg: " << m_last_rcvd;
    m_msgs << actab.getFormattedString();

    return(true);
}




