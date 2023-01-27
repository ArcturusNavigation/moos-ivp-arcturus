#--------------------------------------------------------
# The CMakeLists.txt for:                       pSequence
# Author(s):                              Toya
#--------------------------------------------------------

SET(SRC
  Sequence.cpp
  Sequence_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pSequence ${SRC})

TARGET_LINK_LIBRARIES(pSequence
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

