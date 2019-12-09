/* ______________________________________________________________________
| Workfile : Distance.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef DISTANCE_H
#define DISTANCE_H

#include "IDisplay.h"
#include "Car.h"

class Distance :
	public IDisplay {
	Distance(Car::SPter const& car) : mCar{ car }, mDistance{ CalcDistance(car->GetRPM()) } {}

	virtual void Update() override;

private:
	double mDistance;
	Car::SPter mCar;

	double CalcDistance(unsigned int rpm) const;
};

#endif //DISTANCE_H

