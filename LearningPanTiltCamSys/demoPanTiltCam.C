/*
 * demoPanTiltCam.C
 *
 *  Created on: 31.08.2018
 *      Author: aml
 */


#include "PanTiltCam.H"
#include "CXmlMap.H"
#include <iostream>

int main(int argc, char *argv[]){
	PanTiltCamSys::PanTiltCamDegree ptCam;

	CXmlMap map;

	map.init(2,2,1,500);

	unsigned short SOURCE_SERVER_PORT_;  //Blob detector
	char          *SOURCE_SERVER_ADR_;   //blob detector
	char          *CAM_DEV;              // pan-tilt connection

	try{
		CAM_DEV             = argv[1];
		SOURCE_SERVER_ADR_  = argv[2];
		SOURCE_SERVER_PORT_ = atoi(argv[3]);
	}catch(...){
		cerr << "Can't read command line parameters, terminate process.\n";
		exit(0);
	};

	// open connection to pan-tilt system and
	try{
		ptCam.connect(CAM_DEV, SOURCE_SERVER_ADR_, SOURCE_SERVER_PORT_);
	}catch(string msg){
		cout << "Error: terminate: " << msg << endl;
	}catch(...){
		cout << "Unknown error: terminate." << endl;
	}

	int x,y,p,t;

	do{
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



