/* ______________________________________________________________________
| Workfile : Distance.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Distance.h"

static const double conversionFactorToKMH = 3.6;

void Distance::Update() {
	
	mDistance += CalcDistance(mCar->GetCurrentSpeed());
	if (anaDisp->SendValue(mDistance))
	{
		std::cout << "Distance: " << mDistance << std::endl;
	}
}

double Distance::CalcDistance(double const velocity) const {
	if (velocity != 0) {
		return ((velocity) / conversionFactorToKMH) / 2;
	}
	return 0;
}
