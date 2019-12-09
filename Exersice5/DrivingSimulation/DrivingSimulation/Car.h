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
#include "RPMSensor.h"

#include <iostream>
class Car :
	public Vehicle {

public:

		/**
	 * @brief Constructor, saves the fileName into member and initializes tireDimension and current RPMs
	 * @param -
	 * @return -
	 */
	Car(std::string const& fileName, unsigned int tireDim = 600) : mFileName{ fileName }, mTireDim{ tireDim }, mTireRPM{ 0 }{}

	/**
	 * @brief Calls GetRevolutions of RPM_Sensor and stores delivered value in membervariable, starts Notificationprocess
	 * @param -
	 * @return -
	 */
	void Process();

	/**
	 * @brief Getter
	 * @param -
	 * @return current Rotations per Minute for one Wheel
	 */
	unsigned int GetRPM() const;

	/**
	 * @brief Calculates current speed based on Wheel diameter and RPMs
	 * @param -
	 * @return current Speed 
	 */
	double GetCurrentSpeed() const;

	/**
	 * @brief Replaces old value for Tire Dimension with the given Diameter
	 * @param newDim new Dimension for Tire Diameter
	 * @return -
	 */
	void SetTireDim(unsigned int newDim);
	
	/**
	 * @brief Getter
	 * @param -
	 * @return current Tire Diameter
	 */
	unsigned int GetTireDim() const;

	using SPter = std::shared_ptr<Car>;


private:
	std::string mFileName;
	RPM_Sensor mFrontRight{ mFileName };

	unsigned int mTireRPM;
	unsigned int mTireDim;


};

#endif //CAR_H
