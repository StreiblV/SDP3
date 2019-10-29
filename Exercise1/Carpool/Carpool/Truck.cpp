/*______________________________________________________________________
|Workfile:		Truck.cpp
|Description:	Class for a Vehicle of type Truck
|Name:			Viktoria Streibl						PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#include "Truck.h"
#include <iostream>

using namespace std;

Truck::Truck() {
}

Truck::Truck(std::string const& brand, std::string const& numberplate, Fuel fuel) {
	m_brand = brand;
	m_numberplate = numberplate;
	m_fuel = fuel;
}

Truck::~Truck(){}

ostream& Truck::Print(ostream& ost) {
	if (ost.good()) {
		ost << "Fahrzeugart: LKW" << endl;
		ost << "Marke: " << m_brand << endl;
		ost << "Kennzeichen: " << m_numberplate << endl;
		Vehicle::PrintList(ost);

	}
	return ost;
}

std::unique_ptr<Vehicle> Truck::Clone() {
		return make_unique<Truck>(*this);
}
