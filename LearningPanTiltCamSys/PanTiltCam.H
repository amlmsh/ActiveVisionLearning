/*
 * PanTiltCam.H
 *
 *  Created on: 31.08.2018
 *      Author: aml
 */

#ifndef PANTILTCAM_H_
#define PANTILTCAM_H_

#include "PanTilt.H"
#include "BlobDetector.H"


/**
 *
 * namespace
 *
 */
namespace PanTiltCamSys{

/**
 *
 *
 *
 * \class IPanTiltCam
 *
 *
 * \brief
 *
 *
 *
 */
class IPanTiltCam{
public:
	virtual void connect(string panTiltDev, char *blobDetectorHost, unsigned short blobDetectorPort) = 0;

	virtual void close() = 0;

	/**
	 *
	 * \brief Delivers the curret servo motor position
	 * of the pan motor.
	 *
	 * \@return int servo-motor position in degree within the range [-90;90]
	 *
	 * \throws string "no com" if serial communication is not available
	 */
	virtual int  getPanAngle() = 0;

	/**
	 *
	 * \brief Delivers the curret servo motor position
	 * of the tilt motor.
	 *
	 * \@return int servo-motor position in degree within the range [-90;90]
	 *
	 * \throws string "no com" if serial communication is not available
	 *
	 */
	virtual int  getTiltAngle() = 0;


	/**
	 *
	 * \brief Sets the target position of servo motor steering the pan motor.
	 *
	 * \@return int servo-motor position in degree within the range [-90;90]
	 *
	 * \throws string "no com" if serial communication is not available
	 * \throws string "out or range" if given value is outside the range [-90;90]
	 *
	 *
	 */
	virtual void setPanAngle(int position) = 0;

	/**
	 *
	 * \brief Sets the target position of servo motor steering the tilt motor.
	 *
	 * \@return int servo-motor position in degree within the range [-90;90]
	 *
	 * \throws string "no com" if serial communication is not available
	 * \throws string "out or range" if given value is outside the range [-90;90]
	 *
	 *
	 */
	virtual void setTiltAngle(int position) = 0;

	virtual void   changePanAngle(int deltaPosition) = 0;
	virtual void   changeTiltAngle(int deltaPosition) = 0;


	virtual void getBlobCoord(int *X, int *Y) = 0;

};


/**
 *
 * \class PanTiltCamDegree
 *
 */
class PanTiltCamDegree : public IPanTiltCam{
public:
	PanTiltCamDegree();
	virtual~PanTiltCamDegree();
	virtual void connect(string panTiltDev, char *blobDetectorHost, unsigned short blobDetectorPort);
	virtual void close();
	virtual int  getPanAngle();
	virtual int  getTiltAngle();
	virtual void setPanAngle(int position);
	virtual void setTiltAngle(int position);
	virtual void changePanAngle(int deltaPosition);
	virtual void changeTiltAngle(int deltaPosition);
	virtual void getBlobCoord(int *X, int *Y);
protected:
	BlobDetector::IBlobDetector *blobD_;
	PanTilt::IPanTiltDegree *panTiltDeg_;
};


} // end namespace PanTiltCamSys


#endif /* PANTILTCAM_H_ */
