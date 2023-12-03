#--------------------------------------------------------
# The CMakeLists.txt for:                       pStationKeeping
# Author(s):                              Christian and Janelle
#--------------------------------------------------------

SET(SRC
  StationKeeping.cpp
  StationKeeping_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pStationKeeping ${SRC})

TARGET_LINK_LIBRARIES(pStationKeeping
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

