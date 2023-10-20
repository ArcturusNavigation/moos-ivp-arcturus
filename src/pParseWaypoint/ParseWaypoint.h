/************************************************************/
/*    NAME: Toya Takahashi                                              */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: ParseWaypoint.h                                          */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef ParseWaypoint_HEADER
#define ParseWaypoint_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include "MOOS/libMOOSGeodesy/MOOSGeodesy.h"

class ParseWaypoint : public AppCastingMOOSApp
{
    public:
        ParseWaypoint();
        ~ParseWaypoint();

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

    private:
        std::string m_new_msg;
        std::string m_last_rcvd;

        CMOOSGeodesy m_Geodesy;
        double m_lat_origin;
        double m_lon_origin;
};

#endif 
