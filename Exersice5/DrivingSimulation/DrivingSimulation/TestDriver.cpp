/* ______________________________________________________________________
| Workfile : TestDriver.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Car.h"
#define LOOP_DURATION 25

int main() {
	Car car;

	bool exit = false;

	for(int i = 0; i < LOOP_DURATION; i++){
		car.Process();
		Sleep(500);
	}

	return 0;
}