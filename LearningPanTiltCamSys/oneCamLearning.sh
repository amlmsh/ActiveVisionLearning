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

CAM_PORT=1
CAM_SRV_PORT=$(($BASE_PORT+0))
COLOR_FILTER_PORT=$(($BASE_PORT+10))
BLOB_DETECT_PORT=$(($BASE_PORT+20))


# right camera 
CAM_PAN_TILT_DEV=/dev/ttyUSB0
CAM_INIT_PAN=-25;
CAM_INIT_TILT=20;


CAM_PAN_MIN=-45
CAM_PAN_MAX=-10
CAM_TILT_MIN=7
CAM_TILT_MAX=34

LASER_DEV=/dev/ttyUSB1
LASER_INIT_PAN=0
LASER_INIT_TILT=20





#start blob detector
#
CMD="./stdImgDataServerLapCam $CAM_SRV_PORT $CAM_PORT"
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
CMD="./setPosPanTilt $CAM_PAN_TILT_DEV $CAM_INIT_PAN $CAM_INIT_TILT"
echo $CMD
xterm  -geometry 80x10+0+610 -hold -e $CMD &
echo "wait for cam server to be ready"
echo "...for continue press enter"
read c

xterm  -geometry 80x10+0+610 -hold -e $CMD &
echo "wait for cam server to be ready"
echo "...for continue press enter"
read c


CMD="./demoPanTiltCam $CAM_PAN_TILT_DEV $SERVER $BLOB_DETECT_PORT $CAM_PAN_MIN $CAM_PAN_MAX $CAM_TILT_MIN $CAM_TILT_MAX"
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
