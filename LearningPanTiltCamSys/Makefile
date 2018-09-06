#########################################################################
# FILE NAME Makefile
#           copyright 2006 by University of Wales Aberystwyth
#
# BRIEF MODULE DESCRIPTION
#           Makefile for the standard image server 
#
# History:
#
#  01.09.2009 - initial version 
#
#
#########################################################################

CC = g++


CFLAGS=$(shell pkg-config --cflags opencv)   -std=c++11  -std=c++0x
LIBS=$(shell pkg-config --libs opencv) -lxerces-c  -std=c++11  -std=c++0x



TARGETS = stdImgDataServerSim  testClient stdImgDataServerLapCam stdImgDataServerClientColorFilter stdImgDataServerClientBlobDetector testClientBlobDetector testOppBlobDetector demoPanTiltCam setPosPanTilt


all:	$(TARGETS)

doc:
	doxygen Doxyfile 


Socket.o:	Socket.C
	$(CC) $(CFLAGS) $(INCL) -g -DLINUX -D__LINUX__ -DUNIX -c $<

stdImgDataServerSim.o:	stdImgDataServerSim.C  StdImgDataServerProtocol.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT -c $<

stdImgDataServerLapCam.o:	stdImgDataServerLapCam.C  StdImgDataServerProtocol.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT -c $<

stdImgDataServerClientColorFilter.o:	stdImgDataServerClientColorFilter.C  StdImgDataServerProtocol.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT -c $<
	
stdImgDataServerClientBlobDetector.o:	stdImgDataServerClientBlobDetector.C  StdImgDataServerProtocol.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT -c $<	

BlobDetector.o:	BlobDetector.C  BlobDetector.H StdImgDataServerProtocol.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT -c $<	

testClient.o:	testClient.C  StdImgDataServerProtocol.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<

testClientBlobDetector.o:	testClientBlobDetector.C  StdImgDataServerProtocol.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<
	
testOppBlobDetector.o:	testOppBlobDetector.C BlobDetector.C BlobDetector.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<
	
setPosPanTilt.o:	setPosPanTilt.C
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<	
	
	
SerialCom.o:	SerialCom.C SerialCom.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<

PanTilt.o:	PanTilt.C PanTilt.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<
	
PanTiltCam.o:	PanTiltCam.C PanTiltCam.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<		
	
CBaseMap.o:	CBaseMap.C CBaseMap.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<
	
CXmlMap.o:	CXmlMap.C CXmlMap.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<
	
CMemoryMap.o:	CMemoryMap.C CMemoryMap.H
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<

demoPanTiltCam.o:	demoPanTiltCam.C
	$(CC) $(CFLAGS) $(INCL)   -g -DLINUX -D__LINUX__ -DUNIX -D_REENTRANT   -c $<		

stdImgDataServerSim: Socket.o stdImgDataServerSim.o StdImgDataServerProtocol.H
	$(CC) $(INCL) -I/usr/local/lib   \
	-lpthread -D_REENTRANT \
	-lm -lstdc++  Socket.o  -lpthread \
	stdImgDataServerSim.o -o stdImgDataServerSim
	
stdImgDataServerLapCam: Socket.o stdImgDataServerLapCam.o StdImgDataServerProtocol.H
	$(CC) stdImgDataServerLapCam.o -o stdImgDataServerLapCam   \
	$(LIBS) -lpthread -D_REENTRANT \
	-lm -lstdc++  Socket.o  -lpthread  
		

stdImgDataServerClientColorFilter: Socket.o stdImgDataServerClientColorFilter.o StdImgDataServerProtocol.H
	$(CC) stdImgDataServerClientColorFilter.o -o stdImgDataServerClientColorFilter   \
	$(LIBS) -lpthread -D_REENTRANT \
	-lm -lstdc++  Socket.o  -lpthread 

stdImgDataServerClientBlobDetector: Socket.o stdImgDataServerClientBlobDetector.o StdImgDataServerProtocol.H
	$(CC) stdImgDataServerClientBlobDetector.o -o stdImgDataServerClientBlobDetector   \
	$(LIBS) -lpthread -D_REENTRANT \
	-lm -lstdc++  Socket.o  -lpthread 

testClient: testClient.o Socket.o testClient.C StdImgDataServerProtocol.H  PanTiltCam.o
	$(CC)  testClient.o Socket.o -o testClient $(LIBS) -ldl -lstdc++ -lm -std=c++11 \
	
testClientBlobDetector:	testClientBlobDetector.o Socket.o testClientBlobDetector.C StdImgDataServerProtocol.H
	$(CC)  testClientBlobDetector.o Socket.o -o testClientBlobDetector $(LIBS) -ldl -lstdc++ -lm -std=c++11 \

testOppBlobDetector:	testOppBlobDetector.o Socket.o BlobDetector.o StdImgDataServerProtocol.H
	$(CC)  testOppBlobDetector.o Socket.o BlobDetector.o  -o testOppBlobDetector $(LIBS) -ldl -lstdc++ -lm -std=c++11 \

demoPanTiltCam: PanTiltCam.H PanTiltCam.C demoPanTiltCam.o demoPanTiltCam.o PanTiltCam.o PanTilt.o SerialCom.o Socket.o BlobDetector.o CBaseMap.o CXmlMap.o CMemoryMap.o
	$(CC) $(CFLAGS) demoPanTiltCam.o PanTiltCam.o PanTilt.o SerialCom.o Socket.o BlobDetector.o CBaseMap.o CXmlMap.o -o demoPanTiltCam $(LIBS) -ldl -lstdc++ -lm -std=c++11

setPosPanTilt: setPosPanTilt.o PanTilt.o SerialCom.o 
	$(CC) $(CFLAGS) setPosPanTilt.o PanTilt.o SerialCom.o -o setPosPanTilt $(LIBS) -ldl -lstdc++ -lm -std=c++11


#cleaning up
clean:
	rm -r *.o  *.sh~   $(TARGETS) ./DOXYGENDOC
