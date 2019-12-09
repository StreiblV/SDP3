/* ______________________________________________________________________
| Workfile : Vehicle.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Vehicle.h"

void Vehicle::Attach(IDisplay::SPter const& obs) {
	try {
		if (std::find(mObservers.cbegin(), mObservers.cend(), obs) == mObservers.cend()) {
			mObservers.emplace_back(obs);
		}
	}
	catch (std::bad_alloc const& ex) {
		std::cerr << "Memory allocation error: " << ex.what() << std::endl;
	}
}

void Vehicle::Detach(IDisplay::SPter const& obs) {
	try {
		auto iterObs = std::find(mObservers.cbegin(), mObservers.cend(), obs);
		if (iterObs != mObservers.cend()) {
			mObservers.erase(iterObs);
		}
	}
	catch (std::bad_alloc const& ex) {
		std::cerr << "Memory allocation error: " << ex.what() << std::endl;
	}
}

void Vehicle::NotifyObservers() {
	for (auto elem : mObservers) {
		elem->Update();
	}
}
