#!/bin/bash -e
VNAME="fishnships"
VEHICLE_IP="192.168.1.4"
MOOS_PORT="9000"
PSHARE_PORT="9832"

# Create the .moos file
printf "Preparing shoreside .moos file...\n"
nsplug meta_shoreside.moos targ_shoreside.moos -f \
    VNAME=$VNAME                                  \
    VEHICLE_IP=$VEHICLE_IP                        \
    MOOS_PORT=$MOOS_PORT                          \
    PSHARE_PORT=$PSHARE_PORT

# Launch the processes
echo "Launching shoreside MOOS Community"
pAntler targ_shoreside.moos >& /dev/null &
uMAC -t targ_shoreside.moos
kill -- -$$
