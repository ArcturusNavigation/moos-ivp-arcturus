##############################################################################
# FILE:        moos-ivp-extend/src/CMakeLists.txt
# DATE:        2010/09/07
#              2020/05/09 minor mods
# DESCRIPTION: CMakeLists.txt file for the moos-ivp-extend source directory
##############################################################################


#============================================================================
# Add the libraries in the current directory to the include path
#============================================================================
FILE(GLOB LOCAL_LIBRARY_DIRS ./lib_*)
INCLUDE_DIRECTORIES(${LOCAL_LIBRARY_DIRS})

#============================================================================
# List the subdirectories to build...
#============================================================================
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(iMOOSGateway)
ADD_SUBDIRECTORY(pParseGateway)
ADD_SUBDIRECTORY(iGazeboVessel)
ADD_SUBDIRECTORY(pStationKeeping)

##############################################################################
#                           END of CMakeLists.txt
##############################################################################

