/* ______________________________________________________________________
| Workfile : TestDriver.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Car.h"
#include "IDisplay.h"
#include "Distance.h"
#include "Speed.h"
#include <windows.h>

#define LOOP_DURATION 25

int main() {
	Car car{ "testData.txt" };

	bool exit = false;
	
	Car::SPter pCar{ std::make_shared<Car>(car) };
	IDisplay::SPter distance{ std::make_shared<Distance>(pCar) };
	IDisplay::SPter speed{ std::make_shared<Speed>(pCar) };

	car.Attach(distance);
	car.Attach(speed);

	for(int i = 0; i < LOOP_DURATION; i++){
		car.Process();
		Sleep(500);
	}

	return 0;
}