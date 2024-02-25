/************************************************************/
/*    NAME: Toya Takahashi                                  */
/*    ORGN: MIT, Cambridge MA                               */
/*    FILE: ParseGateway.h                                  */
/*    DATE: December 29th, 1963                             */
/************************************************************/

#ifndef ParseGateway_HEADER
#define ParseGateway_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include "MOOS/libMOOSGeodesy/MOOSGeodesy.h"

class ParseGateway : public AppCastingMOOSApp
{
    public:
        ParseGateway();
        ~ParseGateway();

    protected: // Standard MOOSApp functions to overload  
        bool OnNewMail(MOOSMSG_LIST &NewMail);
        bool Iterate();
        bool OnConnectToServer();
        bool OnStartUp();

    protected: // Standard AppCastingMOOSApp function to overload 
        bool buildReport();

    protected:
        void registerVariables();
        void handleNavReport(std::string report);
        void handleWptReport(std::string report);
        void handleFeatureReport(std::string report);
        void geodesySetup();

    private:
        double m_nav_lat;
        double m_nav_lon;
        double m_nav_x;
        double m_nav_y;
        double m_nav_speed;
        double m_nav_heading;

        std::string m_wpt_msg;
        std::string m_last_rcvd;

        CMOOSGeodesy m_Geodesy;
        double m_lat_origin;
        double m_lon_origin;
};

#endif 
