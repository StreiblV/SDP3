#include "Truck.h"
#include <iostream>

using namespace std;

Truck::~Truck(){}

void Truck::Print() {
	cout << "Fahrzeugart: LKW" << endl;
	cout << "Marke: " << m_brand << endl;
	cout << "Kennzeichen: " << m_numberplate << endl;

	Vehicle::PrintList();
}