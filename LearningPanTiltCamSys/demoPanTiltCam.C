/*
 * demoPanTiltCam.C
 *
 *  Created on: 31.08.2018
 *      Author: aml
 */


#include "PanTiltCam.H"
#include "CXmlMap.H"
#include <iostream>
#include <unistd.h>



int main(int argc, char *argv[]){
	PanTiltCamSys::PanTiltCamDegree ptCam;

	CXmlMap map;

	map.init(2,2,1,500);

	unsigned short SOURCE_SERVER_PORT_;  //Blob detector
	char          *SOURCE_SERVER_ADR_;   //blob detector
	char          *CAM_DEV_;              // pan-tilt connection
	int           PAN_MIN_, PAN_MAX_, TILT_MIN_, TILT_MAX_;

	try{
		CAM_DEV_             = argv[1];
		SOURCE_SERVER_ADR_  = argv[2];
		SOURCE_SERVER_PORT_ = atoi(argv[3]);
		PAN_MIN_            = atoi(argv[4]);
		PAN_MAX_            = atoi(argv[5]);
		TILT_MIN_           = atoi(argv[6]);
		TILT_MAX_           = atoi(argv[7]);
	}catch(...){
		cerr << "Can't read command line parameters, terminate process.\n";
		exit(0);
	};

	// open connection to pan-tilt system and
	try{
		ptCam.connect(CAM_DEV_, SOURCE_SERVER_ADR_, SOURCE_SERVER_PORT_);

		ptCam.setRange(PAN_MIN_, PAN_MAX_, TILT_MIN_, TILT_MAX_);
	}catch(string msg){
		cout << "Error: terminate: " << msg << endl;
	}catch(...){
		cout << "Unknown error: terminate." << endl;
	}

	int x,y,p,t;
	int deltaP, deltaT;


	do{
		deltaP = (rand() % 21) - 10;
		deltaT = (rand() % 21) - 10;
		if(deltaP < 0){
			deltaP -= 5;
		}else if(deltaP > 0){
			deltaP += 5;
		}

		if(deltaT < 0){
			deltaT -= 5;
		}else if(deltaT > 0){
			deltaT += 5;
		}

		ptCam.changePanAngle(deltaP);
		ptCam.changeTiltAngle(deltaT);

		sleep(1);

		cout << "[" << deltaP << ", " << deltaT << "]" << endl;



		ptCam.getBlobCoord(&x,&y);
		p = ptCam.getPanAngle();
		t = ptCam.getTiltAngle();

		cout << "<" << p << ", " << t << ">  ---> ";
		cout << "<" << x << ", " << y << ">" << endl;
	}while(1);






	try{
		ptCam.close();
	}catch(string msg){
		cout << "Error: terminate: " << msg << endl;
	}catch(...){
		cout << "Unknown error: terminate." << endl;
	}
}



