/*______________________________________________________________________
|Workfile:		Car.cpp
|Description:	Class for a Vehicle of type Car
|Name:			Viktoria Streibl						PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#include "Car.h"
#include <iostream>

using namespace std;

Car::Car() {
}

Car::Car(std::string const& brand, std::string const& numberplate, Fuel fuel) {
	m_brand = brand;
	m_numberplate = numberplate;
	m_fuel = fuel;
}

Car::~Car() {};

void Car::Print() {
	cout << "Fahrzeugart: PKW" << endl;
	cout << "Marke: " << m_brand << endl;
	cout << "Kennzeichen: " << m_numberplate << endl;

	Vehicle::PrintList();
}