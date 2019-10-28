/*______________________________________________________________________
|Workfile:		Motorcycle.cpp
|Description:	Class for a Vehicle of type Motorcycle
|Name:			Viktoria Streibl						PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#include "Motorcycle.h"
#include <iostream>

using namespace std;

Motorcycle::Motorcycle() {
}
Motorcycle::Motorcycle(std::string const& brand, std::string const& numberplate, Fuel fuel){
	m_brand = brand;
	m_numberplate = numberplate;
	m_fuel = fuel;
}

Motorcycle::~Motorcycle() {};

void Motorcycle::Print() {
	cout << "Fahrzeugart: Motorrad" << endl;
	cout << "Marke: " << m_brand << endl;
	cout << "Kennzeichen: " << m_numberplate << endl;

	Vehicle::PrintList();
}