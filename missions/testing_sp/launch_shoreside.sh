#!/bin/bash -e
WARP=1

IP_ADDR="localhost"
MOOS_PORT="9000"
PSHARE_PORT="9200"


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
    elif [ "${ARGI:0:5}" = "--ip=" ]; then
        IP_ADDR="${ARGI#--ip=*}"
	    FORCE_IP="yes"
    else 
        echo "Bad argument:" $ARGI " Exiting with code: 1"
        exit 1
    fi
done

#-------------------------------------------------------
#  Part 2: Create the .moos file
#-------------------------------------------------------
printf "Preparing shoreside .moos file...\n"
nsplug meta_shoreside.moos targ_shoreside.moos -f \
    WARP=$WARP                                    \
    IP_ADDR=$IP_ADDR                                \
    PSHARE_PORT=$PSHARE_PORT                \
    MOOS_PORT=$MOOS_PORT                        \
    REGION=$REGION                          \
    FORCE_IP=$FORCE_IP          

#-------------------------------------------------------
#  Part 3: Launch the processes
#-------------------------------------------------------
echo "Launching shoreside MOOS Community"
pAntler targ_shoreside.moos >& /dev/null &
uMAC -t targ_shoreside.moos
kill -- -$$


