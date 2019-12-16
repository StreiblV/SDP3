/* ______________________________________________________________________
| Workfile : Speed.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
		 Viktoria Streibl		PKZ : S1810306013
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Speed.h"

void Speed::Update() {

	mSpeed = mCar->GetCurrentSpeed();

	if (digDisp->SendValue(mSpeed)) {
		std::cout << "Speed: " << mSpeed << std::endl;
	}

}
