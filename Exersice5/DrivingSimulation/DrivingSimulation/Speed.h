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
class Speed : public IDisplay {
public:
	/**
	 * @brief constructor for Speed-Observer
	 * @param Shared-Pointer to a Car
	 * @return -
	 */
	Speed(Car::SPter const& car) : mCar{ car }, mSpeed{ car->GetCurrentSpeed() } {}

	/**
	 * @brief gets current speed of the Car pointed to
	 * @param -
	 * @return -
	 */
	virtual void Update() override;

private:
	double mSpeed;
	Car::SPter mCar;
};

#endif //SPEED_H

