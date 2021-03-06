/*
 * setPosPanTilt.C
 *
 *  Created on: 06.09.2018
 *      Author: aml
 */

#include "SerialCom.H"
#include "PanTilt.H"

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	PanTilt::PanTiltDegree leftCam;

	try {

		if (argc == 4) {
			leftCam.openSerialCom(argv[1]);


			int panPos  = atoi(argv[2]);
			int tiltPos = atoi(argv[3]);

			cout << "target: pan = " << panPos << "  tilt = " << tiltPos <<endl;


			leftCam.setTiltAngle(tiltPos);
			leftCam.setPanAngle(panPos);

			panPos = leftCam.getPanAngle();
			tiltPos = leftCam.getTiltAngle();
			cout << "actual: pan = " << panPos << "  tilt = " << tiltPos <<endl;

			leftCam.closeSerialCom();
		} else {
			cout << "No connection.\n";
		}

	} catch (string msg) {
		cout << "Error, terminate: " << msg << endl;
	} catch (...) {
		cout << "Unknown error, terminate.";
	}

	return 0;
}
;


