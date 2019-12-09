/* ______________________________________________________________________
| Workfile : Speed.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Speed.h"
#include "WindowsDisplay.h"

void Speed::Update() {
	WindowsDisplay::SPtr digDisp = std::make_shared<DigitalDisplay>();

	mSpeed = mCar->GetCurrentSpeed();
}
