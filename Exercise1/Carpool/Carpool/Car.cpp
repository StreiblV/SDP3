#include "Car.h"
#include <iostream>

using namespace std;

Car::~Car() {};

void Car::Print() {
	cout << "Fahrzeugart: PKW" << endl;
	cout << "Marke: " << m_brand << endl;
	cout << "Kennzeichen: " << m_numberplate << endl;

	Vehicle::PrintList();
}