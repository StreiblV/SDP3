#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle(){
	m_brand = "";
	m_numberplate = "";
	m_fuel = Fuel::Petrol;
}

Vehicle::Vehicle(string brand, string numberplate, Fuel fuel) {
	m_brand = brand;
	m_numberplate = numberplate;
	m_fuel = fuel;
}

Vehicle::~Vehicle() {};

string Vehicle::GetNumberplate() {
	return m_numberplate;
}

void Vehicle::SetBrand(string brand) {
	m_brand = brand;
}

void Vehicle::SetNumberplate(string numberplate) {
	m_numberplate = numberplate;
}

void Vehicle::SetFuel(Fuel fuel) {
	m_fuel = fuel;
}

void Vehicle::PrintList() {
	m_logbook.PrintLogEntries();
}