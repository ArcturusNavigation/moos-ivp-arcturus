#!/bin/bash -e
WARP=1
VNAME="fishnships"
VPORT="9002"
SHARE_LISTEN="9102"
SHORE_IP="localhost"
SHORE_LISTEN="9100"

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
    VNAME=$VNAME                             \
    VPORT=$VPORT                             \
    SHARE_LISTEN=$SHARE_LISTEN               \
    SHORE_IP=$SHORE_IP                       \
    SHORE_LISTEN=$SHORE_LISTEN

printf "Preparing vehicle .bhv file...\n"
nsplug meta_vehicle.bhv targ_$VNAME.bhv -f   \
    VNAME=$VNAME                             

#----------------------------------------------------------
#  Part 3: Launch the processes
#----------------------------------------------------------
echo "Launching $VNAME MOOS Community"
pAntler targ_$VNAME.moos >& /dev/null &
uMAC -t targ_$VNAME.moos
kill -- -$$
