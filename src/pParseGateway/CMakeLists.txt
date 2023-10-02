#--------------------------------------------------------
# The CMakeLists.txt for:                       pParseGateway
# Author(s):                              Toya Takahashi
#--------------------------------------------------------

SET(SRC
    ParseGateway.cpp
    ParseGateway_Info.cpp
    main.cpp
    )

ADD_EXECUTABLE(pParseGateway ${SRC})

TARGET_LINK_LIBRARIES(pParseGateway
    ${MOOS_LIBRARIES}
    ${MOOSGeodesy_LIBRARIES}
    geometry
    apputil
    mbutil
    m
    pthread
    )

