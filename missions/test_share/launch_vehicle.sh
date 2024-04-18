#!/bin/bash -e
VNAME="fishnships"
SHORE_IP="192.168.1.3"
MOOS_PORT="9001"
PSHARE_PORT="9832"

# Create the .moos file
printf "Preparing vehicle .moos file...\n"
nsplug meta_vehicle.moos targ_$VNAME.moos -f \
    VNAME=$VNAME                             \
    SHORE_IP=$SHORE_IP                       \
    MOOS_PORT=$MOOS_PORT                     \
    PSHARE_PORT=$PSHARE_PORT

# Launch the processes
echo "Launching $VNAME MOOS Community"
pAntler targ_$VNAME.moos >& /dev/null &
uMAC -t targ_$VNAME.moos
kill -- -$$
