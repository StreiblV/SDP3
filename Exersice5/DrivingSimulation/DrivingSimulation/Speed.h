/* ______________________________________________________________________
| Workfile : Speed.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef SPEED_H
#define SPEED_H
#include "IDisplay.h"
#include "Car.h"
class Speed :
	public IDisplay {
public:
	Speed(Car::SPter const& car) : mCar{ car }, mSpeed{ car->GetCurrentSpeed() } {}

	virtual void Update() override;

private:
	double mSpeed;
	Car::SPter mCar;
};

#endif //SPEED_H

