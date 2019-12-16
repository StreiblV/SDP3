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
		else {
			throw std::exception("Observer to attach is already contained!");
		}
	}
	catch (std::exception const& ex) {
		std::cerr << "Error while attaching: " << ex.what() << std::endl;
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
		else {
			throw std::exception("Observer to detach could not be found!");
		}
	}
	catch (std::exception const& ex) {
		std::cerr << "Error while detaching: " << ex.what() << std::endl;
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
