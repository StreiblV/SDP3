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
	void Attach(IDisplay::SPter const& obs);
	void Detach(IDisplay::SPter const& obs);

protected:
	void NotifyObservers();

private:
	std::vector<IDisplay::SPter> mObservers;
};

#endif //VEHICLE_H

