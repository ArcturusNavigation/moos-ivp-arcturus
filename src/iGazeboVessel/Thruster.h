/*****************************************************************/
/*    NAME: Michael Benjamin                                     */
/*    ORGN: Dept of Mechanical Engineering, MIT, Cambridge MA    */
/*    FILE: Thruster.h                                           */
/*    DATE: April 11th 2020                                      */
/*    NOTE: Modified for iGazeboVessel control (mikedef)         */
/*                                                               */
/* This is unreleased BETA code. No permission is granted or     */
/* implied to use, copy, modify, and distribute this software    */
/* except by the author(s), or those designated by the author.   */
/*****************************************************************/

#ifndef THRUSTER_HEADER
#define THRUSTER_HEADER

#include <string>
#include <list>
#include <math.h>   // for fabs

class Thruster
{
public:
  Thruster();
  ~Thruster() {};

  // SET functions:
  bool  setDriveMode(std::string drive_mode);
  bool  setMaxRudder(std::string max_rud);
  bool  setMaxRudder(double max_rud);
  bool  setMaxThrust(std::string max_thr);
  bool  setMaxThrust(double max_thr);
  bool  setMinThrust(std::string min_thr);
  bool  setRFactor(std::string rfactor);
  bool  setRudder(std::string des_rud);
  bool  setRudder(double des_rud);
  bool  setThrust(std::string des_thr);
  bool  setThrust(double des_thr);
  bool  setThrusterSpeed(std::string des_thrX, std::string thr_side);
  bool  setThrusterSpeed(double des_thrX, std::string thr_side);
    
  // GET functions:
  double  getRudder() const        {return m_des_rud;};
  double  getThrust() const        {return m_des_thr;};
  double  getThrustLeft() const    {return m_des_thrL;};
  double  getThrustRight() const   {return m_des_thrR;};
  double  getMinThrust() const     {return m_min_thr;};
  double  getMaxThrust() const     {return m_max_thr;};
  double  getRFactor() const       {return m_rfactor;};
  std::string getDriveMode() const {return m_drive_mode;}; 

  std::list<std::string>  getWarnings() const {return m_warnings;};

  bool  calcDiffThrust();  
protected:
  void  addWarning(std::string warning);

private: // Config params
  double       m_max_rud;
  double       m_max_thr;
  double       m_min_thr;
  double       m_rfactor;
  std::string  m_drive_mode;
  unsigned int m_max_list_size;

private: // State vars
  double  m_des_thrL;
  double  m_des_thrR;
  double  m_des_thr;
  double  m_des_rud;

  std::list<std::string>  m_warnings;
};

#endif


