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

#include <iostream>
class Car :
	public Vehicle {

public:

	Car(std::string const& fileName, unsigned int tireDim = 600) : mFileName{ fileName }, mTireDim{ tireDim }, mTireRPM{ 0 }{}

	/**
	 * @brief
	 * @param
	 * @return
	 */
	void Process();

	/**
	 * @brief
	 * @param
	 * @return
	 */
	unsigned int GetRPM() const;

	/**
	 * @brief
	 * @param
	 * @return
	 */
	double GetCurrentSpeed() const;

	/**
	 * @brief
	 * @param
	 * @return
	 */
	void SetTireDim(unsigned int newDim);
	
	/**
	 * @brief
	 * @param
	 * @return
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
