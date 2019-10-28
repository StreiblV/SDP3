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

unsigned long Vehicle::GetMileage() const{
	return m_logbook.GetTotalDistance();
}

void Vehicle::AddNewLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance) {
	Logbook::Date date = CreateDate(day, month, year);
	m_logbook.AddNewEntry(date, distance);
}

void Vehicle::ChangeLastLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance) {
	Logbook::Date date = CreateDate(day, month, year);
	m_logbook.ChangeLastEntry(date, distance);
}

Logbook::Date Vehicle::CreateDate(size_t const& day, size_t const& month, size_t const& year) {
	Logbook::Date date;
	date.day = 0;
	date.month = 0;
	date.year = 0;

	try {
		if (day <= 0 && day > m_daysPerMonth) {
			throw exception("Wrong Date: Your day is not valid");
		}
		if (month <= 0 && month > m_monthPerYear) {
			throw exception("Wrong Date: Your month is not valid");
		}
		if (year < 0) {
			throw exception("Wrong Date: Your year is not valid");
		}

		if (year > m_currentYear || month > m_currentMonth || day > m_currentDay) {
			throw exception("Wrong Date: Back to the Future?");
		}

		date.day = day;
		date.month = month;
		date.year = year;
	}
	catch(exception const& ex){
		cerr << ex.what() << endl;
	}

	return date;
}

void Vehicle::setCurrentDate() {
	time_t now = time(0);
	tm* ltm = localtime(&now);

	m_currentYear = 1900 + ltm->tm_year;
	m_currentMonth = 1 + ltm->tm_mon;
	m_currentDay = ltm->tm_mday;
}
