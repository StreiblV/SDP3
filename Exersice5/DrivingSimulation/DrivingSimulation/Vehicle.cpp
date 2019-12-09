/* ______________________________________________________________________
| Workfile : Vehicle.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include <algorithm>
#include "Vehicle.h"

void Vehicle::Attach(IDisplay::SPter const& obs) {
	if (std::find(mObservers.cbegin(), mObservers.cend(), obs) == mObservers.cend()) {
		mObservers.emplace_back(obs);
	}
}

void Vehicle::Detach(IDisplay::SPter const& obs) {
	auto iterObs = std::find(mObservers.cbegin(), mObservers.cend(), obs);
	if (iterObs != mObservers.cend()) {
		mObservers.erase(iterObs);
	}
}

void Vehicle::NotifyObservers() {
	for (auto elem : mObservers) {
		elem->Update();
	}
}
