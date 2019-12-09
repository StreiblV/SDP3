/* ______________________________________________________________________
| Workfile : Car.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include "RPM_Sensor.h"
class Car :
	public Vehicle {

public:
	void Process();
	using SPter = std::shared_ptr<Car>;

	unsigned int GetRPM() const;
	double GetCurrentSpeed() const;

	void SetTireDim(unsigned int newDim);
	unsigned int GetTireDim() const;

private:
	RPM_Sensor::SPter mFrontRight;
	unsigned int mTireRPM;
	unsigned int mTireDim;


};

#endif //CAR_H
