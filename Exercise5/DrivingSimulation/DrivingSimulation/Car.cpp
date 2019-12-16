/* ______________________________________________________________________
| Workfile : Car.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Car.h"

static const double PI = 3.14159265359;
static const double conversionFactorToKMH = 3.6;

void Car::Process() {
	try {
		mTireRPM = mFrontRight.GetRevolutions();
	}
	catch (std::exception const& ex) {
		std::cerr << "Error while fetching Revolutions: "<< ex.what() << std::endl;
	}
	NotifyObservers();
}

unsigned int Car::GetRPM() const {
	return mTireRPM;
}

double Car::GetCurrentSpeed() const {
	return ((static_cast<double>(mTireRPM)/60)* mTireDim * PI * conversionFactorToKMH);
}

void Car::SetTireDim(double newDim) {
	if (newDim > 0) {
		mTireDim = newDim;
	}
	else {
		throw std::exception("Tiredimension must be greater than 0!");
	}
}

double Car::GetTireDim() const {
	return mTireDim;
}
