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
	/**
	 * @brief constructor for concrete observer Distance; initializes Shared-Pointer and Distance
	 * @param shared pointer to a car
	 * @return 
	 */
	Distance(Car::SPter const& car) : mCar{ car }, mDistance{ CalcDistance(car->GetRPM()) } {}

	/**
	 * @brief requests current revolutions, calculates distance travelled and saves it into member
	 * @param -
	 * @return -
	 */
	virtual void Update() override;

private:
	double mDistance;
	Car::SPter mCar;

	/**
	 * @brief Calculates Distance based on the current Speed
	 * @param velocity: current velocity the car travels 
	 * @return current Distance travelled
	 */
	double CalcDistance(unsigned int const velocity) const;
};

#endif //DISTANCE_H

