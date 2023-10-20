#--------------------------------------------------------
# The CMakeLists.txt for:                       pParseWaypoint
# Author(s):                              Toya Takahashi
#--------------------------------------------------------

SET(SRC
    ParseWaypoint.cpp
    ParseWaypoint_Info.cpp
    main.cpp
    )

ADD_EXECUTABLE(pParseWaypoint ${SRC})

TARGET_LINK_LIBRARIES(pParseWaypoint
    ${MOOS_LIBRARIES}
    ${MOOSGeodesy_LIBRARIES}
    geometry
    apputil
    mbutil
    m
    pthread)

