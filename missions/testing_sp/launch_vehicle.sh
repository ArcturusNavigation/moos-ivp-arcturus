#!/bin/bash -e
WARP=1

IP_ADDR="localhost"
MOOS_PORT="9001"
PSHARE_PORT="9201"

SHORE_IP="localhost"
SHORE_PSHARE="9200"
VNAME="fishnships"


#----------------------------------------------------------
#  Part 1: Check for and handle command-line arguments
#----------------------------------------------------------
for ARGI; do
    if [ "${ARGI}" = "--help" -o "${ARGI}" = "-h" ] ; then
        echo "launch.sh [SWITCHES] [time_warp]   "
        echo "  --help, -h           Show this help message            " 
        exit 0;
    elif [ "${ARGI//[^0-9]/}" = "$ARGI" -a "$WARP" = 1 ]; then 
        WARP=$ARGI
    elif [ "${ARGI:0:8}" = "--shore=" ]; then
        SHORE_IP="${ARGI#--shore=*}"
    else 
        echo "Bad argument:" $ARGI " Exiting with code: 1"
        exit 1
    fi
done

#----------------------------------------------------------
#  Part 2: Create the .moos and .bhv files
#----------------------------------------------------------
printf "Preparing vehicle .moos file...\n"
nsplug meta_vehicle.moos targ_$VNAME.moos -f \
    WARP=$WARP                               \
    PSHARE_PORT=$PSHARE_PORT                \   
    VNAME=$VNAME                            \
    IP_ADDR=$IP_ADDR                        \
    SHORE_IP=$SHORE_IP                      \
    SHORE_PSHARE=$SHORE_PSHARE              \
    MOOS_PORT=$MOOS_PORT                              

#----------------------------------------------------------
#  Part 3: Launch the processes
#----------------------------------------------------------
echo "Launching $VNAME MOOS Community"
pAntler targ_$VNAME.moos >& /dev/null &
uMAC -t targ_$VNAME.moos
kill -- -$$
