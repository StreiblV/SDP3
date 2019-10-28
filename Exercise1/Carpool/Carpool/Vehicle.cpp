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

bool Vehicle::operator == (Vehicle const& vehicle) const {
	return (this->m_numberplate == vehicle.m_numberplate);
}

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

unsigned long Vehicle::GetMileage() const{
	return m_logbook.GetTotalDistance();
}

void Vehicle::AddNewLogbookEntry(string const& date, int const& distance) {
	m_logbook.AddNewEntry(date, distance);
}

void Vehicle::ChangeLastLogbookEntry(string const& date, int const& distance) {
	m_logbook.ChangeLastEntry(date, distance);
}
