#!/bin/bash -e
WARP=1
VNAME="fishnships"
SHORE_IP="192.168.1.4"
MOOS_PORT="9001"
PSHARE_PORT="9832"

# Create the .moos and .bhv files
printf "Preparing vehicle .moos file...\n"
nsplug meta_vehicle.moos targ_$VNAME.moos -f \
    WARP=$WARP                               \
    VNAME=$VNAME                             \
    SHORE_IP=$SHORE_IP                       \
    MOOS_PORT=$MOOS_PORT                     \
    PSHARE_PORT=$PSHARE_PORT
printf "Preparing vehicle .bhv file...\n"
nsplug meta_vehicle.bhv targ_$VNAME.bhv -f   \
    VNAME=$VNAME                             

# Launch the processes
echo "Launching $VNAME MOOS Community"
pAntler targ_$VNAME.moos >& /dev/null &
uMAC -t targ_$VNAME.moos
kill -- -$$
