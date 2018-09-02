/*
 * demoPanTiltCam.C
 *
 *  Created on: 31.08.2018
 *      Author: aml
 */

#include "PanTiltCam.H"
#include <iostream>

int main(int argc, char *argv[]){
	PanTiltCamSys::PanTiltCamDegree ptCam;

	unsigned short SOURCE_SERVER_PORT_;
	char          *SOURCE_SERVER_ADR_;

	try{
		SOURCE_SERVER_ADR_  = argv[2];
		SOURCE_SERVER_PORT_ = atoi(argv[3]);
	}catch(...){
		cerr << "Can't read command line parameters, terminate process.\n";
		exit(0);
	};

	try{

		ptCam.connect(argv[1], SOURCE_SERVER_ADR_, SOURCE_SERVER_PORT_);

		ptCam.close();

	}catch(string msg){
		cout << "Error: terminate: " << msg << endl;
	}catch(...){
		cout << "Unknown error: terminate." << endl;
	}
}



