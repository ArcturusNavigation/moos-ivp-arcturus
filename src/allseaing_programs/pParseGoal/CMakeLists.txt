#--------------------------------------------------------
# The CMakeLists.txt for:                       pParseGoal
# Author(s):                              Christian and Janelle
#--------------------------------------------------------

SET(SRC
  ParseGoal.cpp
  ParseGoal_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pParseGoal ${SRC})

TARGET_LINK_LIBRARIES(pParseGoal
   ${MOOS_LIBRARIES}
   apputil
   mbutil
   m
   pthread)

