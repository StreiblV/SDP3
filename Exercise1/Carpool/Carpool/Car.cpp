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
	//set brand, numberplate and fuel
	m_brand = brand;
	m_numberplate = numberplate;
	m_fuel = fuel;
}

Car::~Car() {};

ostream& Car::Print(ostream& ost) {
	//chek if ostream is valid
	if (ost.good()) {
		ost << "Fahrzeugart: PKW" << endl;
		ost << "Marke: " << m_brand << endl;
		ost << "Kennzeichen: " << m_numberplate << endl;
		//print all logbook entries
		Vehicle::PrintList(ost);
	}
	
	return ost;
}

std::unique_ptr<Vehicle> Car::Clone() {
	return make_unique<Car>(*this);
}
