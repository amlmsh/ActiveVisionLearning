/*
 * PanTiltCam.C
 *
 *  Created on: 31.08.2018
 *      Author: aml
 */

#include "PanTiltCam.H"
#include <iostream>


namespace PanTiltCamSys{

PanTiltCamDegree::PanTiltCamDegree(){
	blobD_ = NULL;
	panTiltDeg_ = NULL;
};

PanTiltCamDegree::~PanTiltCamDegree(){
	this->close();
};

void PanTiltCamDegree::connect(string panTiltDev, char *blobDetectorHost, unsigned short blobDetectorPort){

	try{
		panTiltDeg_ = new PanTilt::PanTiltDegree();
	}catch(...){
		panTiltDeg_ = NULL;
		throw string("Could not create panTiltDegree");
	}

	try{
		blobD_ = new BlobDetector::BlobDetector();
	}catch(...){
		delete panTiltDeg_;
		panTiltDeg_ = NULL;
		blobD_ = NULL;
		throw string("Could not create panTiltDegree");
	}

	try{
		this->panTiltDeg_->openSerialCom(panTiltDev);
	}catch(string msg){
		delete this->panTiltDeg_;
		this->panTiltDeg_ = NULL;
		delete this->blobD_;
		blobD_ = NULL;
		string msg1("Cloud not open connection to pan-tilt system ");
		msg1 += msg;
		throw msg1;
	}catch(...){
		delete this->panTiltDeg_;
		this->panTiltDeg_ = NULL;
		delete this->blobD_;
		blobD_ = NULL;
		throw string ("Cloud not open connection to pan-tilt system ");
	}

	try{
		this->blobD_->connect(blobDetectorHost, blobDetectorPort);
	}catch(string msg){
		this->panTiltDeg_->closeSerialCom();
		delete this->panTiltDeg_;
		this->panTiltDeg_ = NULL;
		delete this->blobD_;
		blobD_ = NULL;
		string msg1("Cloud not open connection to blobDetector:");
		msg1 += msg;
		throw msg1;
	}catch(...){
		this->panTiltDeg_->closeSerialCom();
		delete this->panTiltDeg_;
		this->panTiltDeg_ = NULL;
		delete this->blobD_;
		blobD_ = NULL;
		throw string ("Cloud not open connection to blobDetector ");
	}

};

void PanTiltCamDegree::close(){
	if(blobD_ != NULL){
		blobD_->close();
		delete blobD_;
		blobD_ = NULL;
	}
	if(panTiltDeg_ != NULL){
		panTiltDeg_->closeSerialCom();
		delete panTiltDeg_;
		panTiltDeg_ = NULL;
	}

};

int  PanTiltCamDegree::getPanAngle(){
	if(this->panTiltDeg_ == NULL){
		string msg("error in method getPanAngle: ");
		msg += "pan-tilt system is NULL pointer reference (not connected)";
		throw msg;
	}

	if(this->blobD_ == NULL){
		string msg("error in method getPanAngle: ");
		msg += "blob detector is NULL pointer reference (not connected)";
		throw msg;
	}

	try{
		return (this->panTiltDeg_->getPanAngle());
	}catch(string msg){
		throw msg;
	}catch(...){
		throw string("unknown error (getPanAngle)");
	};
};

int  PanTiltCamDegree::getTiltAngle(){
	if(this->panTiltDeg_ == NULL){
		string msg("error in method getTiltAngle: ");
		msg += "pan-tilt system is NULL pointer reference (not connected)";
		throw msg;
	}

	if(this->blobD_ == NULL){
		string msg("error in method getTiltAngle: ");
		msg += "blob detector is NULL pointer reference (not connected)";
		throw msg;
	}

	try{
		return (this->panTiltDeg_->getTiltAngle());
	}catch(string msg){
		throw msg;
	}catch(...){
		throw string("unknown error (getTiltAngle)");
	};


};

void PanTiltCamDegree::setPanAngle(int position){
	if(this->panTiltDeg_ == NULL){
		string msg("error in method setPanAngle: ");
		msg += "pan-tilt system is NULL pointer reference (not connected)";
		throw msg;
	}

	if(this->blobD_ == NULL){
		string msg("error in method setPanAngle: ");
		msg += "blob detector is NULL pointer reference (not connected)";
		throw msg;
	}

	int targetPos = position;
	if(targetPos < minPan_){
		targetPos = minPan_;
	}else if(targetPos > maxPan_){
		targetPos = maxPan_;
	}

	try{
		this->panTiltDeg_->setPanAngle(targetPos);
	}catch(string msg){
		throw msg;
	}catch(...){
		throw string("unknown error (setPanAngle)");
	};


};

void PanTiltCamDegree::setTiltAngle(int position){
	if(this->panTiltDeg_ == NULL){
		string msg("error in method setTiltAngle: ");
		msg += "pan-tilt system is NULL pointer reference (not connected)";
		throw msg;
	}

	if(this->blobD_ == NULL){
		string msg("error in method setTiltAngle: ");
		msg += "blob detector is NULL pointer reference (not connected)";
		throw msg;
	}



	int targetPos = position;
	if(targetPos < minTilt_){
		targetPos = minTilt_;
	}else if(targetPos > maxTilt_){
		targetPos = maxTilt_;
	}

	try{
		this->panTiltDeg_->setTiltAngle(targetPos);
	}catch(string msg){
		throw msg;
	}catch(...){
		throw string("unknown error (setTiltAngle)");
	};

};

void PanTiltCamDegree::changePanAngle(int deltaPosition){
	if(this->panTiltDeg_ == NULL){
		string msg("error in method changePanAngle: ");
		msg += "pan-tilt system is NULL pointer reference (not connected)";
		throw msg;
	}

	if(this->blobD_ == NULL){
		string msg("error in method changePanAngle: ");
		msg += "blob detector is NULL pointer reference (not connected)";
		throw msg;
	}


	try{
		int targetPos = this->getPanAngle() + deltaPosition;
		this->setPanAngle(targetPos);
	}catch(string msg){
		throw msg;
	}catch(...){
		throw string("unknown error (changePanAngle)");
	};

};

void PanTiltCamDegree::changeTiltAngle(int deltaPosition){
	if(this->panTiltDeg_ == NULL){
		string msg("error in method changeTiltAngle: ");
		msg += "pan-tilt system is NULL pointer reference (not connected)";
		throw msg;
	}

	if(this->blobD_ == NULL){
		string msg("error in method changeTiltAngle: ");
		msg += "blob detector is NULL pointer reference (not connected)";
		throw msg;
	}

	try{
		int targetPos = this->getTiltAngle() + deltaPosition;
		cout << "change to position " << targetPos << endl;
		this->setTiltAngle(targetPos);
	}catch(string msg){
		throw msg;
	}catch(...){
		throw string("unknown error (changeTiltAngle)");
	};

};


void PanTiltCamDegree::setRange(int minPan, int maxPan, int minTilt, int maxTilt){
	if((maxPan - minPan) < 0){
		throw string("pan range wrong (min > max)");
	}
	if((maxTilt - minTilt) < 0){
		throw string("tilt range wrong (min > max)");
	}

	this->minPan_  = minPan;
	this->maxPan_  = maxPan;
	this->minTilt_ = minTilt;
	this->maxTilt_ = maxTilt;
}

void PanTiltCamDegree::getBlobCoord(int *X, int *Y){
	this->blobD_->getBlobCoord(X,Y);
}

} // end namespace PanTiltCamSys
