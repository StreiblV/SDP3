#include "Motorcycle.h"
#include <iostream>

using namespace std;

Motorcycle::~Motorcycle() {};

void Motorcycle::Print() {
	cout << "Fahrzeugart: Motorrad" << endl;
	cout << "Marke: " << m_brand << endl;
	cout << "Kennzeichen: " << m_numberplate << endl;

	Vehicle::PrintList();
}