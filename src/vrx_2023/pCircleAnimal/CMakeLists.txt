#--------------------------------------------------------
# The CMakeLists.txt for:                       pCircleAnimal
# Author(s):                              Toya Takahashi
#--------------------------------------------------------

SET(SRC
    CircleAnimal.cpp
    CircleAnimal_Info.cpp
    main.cpp
    )

ADD_EXECUTABLE(pCircleAnimal ${SRC})

TARGET_LINK_LIBRARIES(pCircleAnimal
    ${MOOS_LIBRARIES}
    ${MOOSGeodesy_LIBRARIES}
    geometry
    apputil
    mbutil
    m
    pthread)

