#!/bin/bash 
#
#

if [ $# -eq 0 ]
then
echo "$0 : You must give/supply one valid base port number"
echo 
exit 1
fi

if [ $1 -le 5000 ]
then
echo "$0 : set base port number to 5000"
echo
BASE_PORT=5000
else
BASE_PORT=$1
fi


SERVER="127.0.0.1"

BASE_PORT=7000

CAM1_PORT=1
CAM_SRV_PORT=$(($BASE_PORT+0))
COLOR_FILTER_PORT=$(($BASE_PORT+10))
BLOB_DETECT_PORT=$(($BASE_PORT+20))



LASER_DEV=/dev/ttyUSB2
LASER_INIT_PAN=17
LASER_INIT_TILT=-10

CAM1_DEV=/dev/ttyUSB0
CAM_INIT_PAN=0;
CAM_INIT_TILT=0;




#start blob detector
#
CMD="./stdImgDataServerLapCam $CAM_SRV_PORT $CAM1_PORT"
echo $CMD
xterm  -geometry 80x10+0+610 -hold -e $CMD &
echo "wait for cam server to be ready"
echo "...for continue press enter"
read c


CMD="./stdImgDataServerClientColorFilter $COLOR_FILTER_PORT $SERVER $CAM_SRV_PORT"
echo $CMD
xterm  -geometry 80x10+0+610 -hold -e $CMD &
echo "wait for cam server to be ready"
echo "...for continue press enter"
read c


CMD="./stdImgDataServerClientBlobDetector $BLOB_DETECT_PORT $SERVER $COLOR_FILTER_PORT"
echo $CMD
xterm  -geometry 80x10+0+610 -hold -e $CMD &
echo "wait for cam server to be ready"
echo "...for continue press enter"
read c


#move laser to specified position
#
CMD="./setPosPanTilt $LASER_DEV $LASER_INIT_PAN $LASER_INIT_TILT"
echo $CMD
xterm  -geometry 80x10+0+610 -hold -e $CMD &
echo "wait for cam server to be ready"
echo "...for continue press enter"
read c

xterm  -geometry 80x10+0+610 -hold -e $CMD &
echo "wait for cam server to be ready"
echo "...for continue press enter"
read c


#move cam to specified position
#
CMD="./setPosPanTilt $CAM1_DEV $CAM_INIT_PAN $CAM_INIT_TILT"
echo $CMD
xterm  -geometry 80x10+0+610 -hold -e $CMD &
echo "wait for cam server to be ready"
echo "...for continue press enter"
read c

xterm  -geometry 80x10+0+610 -hold -e $CMD &
echo "wait for cam server to be ready"
echo "...for continue press enter"
read c


CMD="./demoPanTiltCam $CAM1_DEV $SERVER $BLOB_DETECT_PORT"
echo
echo "You can now start learning via:"
echo $CMD


echo "Press CTRL-C  to terminate all processes"
while true
do 
  n=1
done


echo $CMD
xterm  -geometry 30x10+200+780 -hold -e $CMD &
echo "for continue press enter"
read c
