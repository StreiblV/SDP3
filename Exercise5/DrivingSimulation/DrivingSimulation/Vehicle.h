/* ______________________________________________________________________
| Workfile : Vehicle.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef VEHICLE_H
#define VEHICLE_H

#include "Object.h"
#include "IDisplay.h"

#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

class Vehicle :
	public Object {
public:

	/**
	 * @brief Adds given shared_ptr to observer container
	 * @param obs shared pointer of type IDisplay, which will be added to the container
	 * @return
	 */
	void Attach(IDisplay::SPter const& obs);

	/**
	 * @brief Removes given observer-ptr from container if it`s contained
	 * @param obs shared pointer of type IDisplay, which will be added to the container
	 * @return -
	 */
	void Detach(IDisplay::SPter const& obs);

protected:
	/**
	 * @brief iterates through vector of Observers and calls Update() on every observer
	 * @param -
	 * @return -
	 */
	void NotifyObservers();

private:
	std::vector<IDisplay::SPter> mObservers;
};

#endif //VEHICLE_H

