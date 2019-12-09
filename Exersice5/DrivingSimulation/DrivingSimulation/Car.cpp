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
	mTireRPM = frontRight.GetRevolutions();
	NotifyObservers();
}

unsigned int Car::GetRPM() const {
	return mTireRPM;
}

double Car::GetCurrentSpeed() const {
	return ((static_cast<double>(mTireRPM)/60)* mTireDim * PI * conversionFactorToKMH);
}

void Car::SetTireDim(unsigned int newDim) {
	if (newDim > 0) {
		mTireDim = newDim;
	}
	else {
		throw std::exception("Tiredimension must be greater than 0!");
	}
}

unsigned int Car::GetTireDim() const {
	return mTireDim;
}
