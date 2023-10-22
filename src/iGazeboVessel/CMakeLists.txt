#--------------------------------------------------------
# The CMakeLists.txt for:                       iGazeboVessel
# Author(s):                              
#--------------------------------------------------------

SET(SRC
  GazeboVessel.cpp
  GazeboVessel_Info.cpp
  main.cpp
  Thruster.cpp
  VehRotController.cpp
)

ADD_EXECUTABLE(iGazeboVessel ${SRC})

TARGET_LINK_LIBRARIES(iGazeboVessel
   ${MOOS_LIBRARIES}
   ${MOOSGeodesy_LIBRARIES}
   geometry
   apputil
   mbutil
   m
   pthread)

