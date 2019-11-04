/*______________________________________________________________________
|Workfile:		Vehicles.cpp
|Description:	Base Class for different Vehicletypes
|Name:			Viktoria Streibl						PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#include "Vehicle.h"
using namespace std;

Vehicle::Vehicle() {
	//set default values
	m_brand = "";
	m_numberplate = "";
	m_fuel = Fuel::Petrol;

	setCurrentDate();
}

Vehicle::~Vehicle() {};

//copy
Vehicle& Vehicle::operator=(Vehicle const& toCopy) {
	if (&toCopy != this)  {
		m_logbook = toCopy.m_logbook;
	}
	return *this;
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

ostream& Vehicle::PrintList(ostream& ost) {
	//print all entries of logbook
	m_logbook.PrintLogEntries(ost);
	return ost;
}

unsigned long Vehicle::GetMileage() const{
	//return total driven kilometers by vehicle
	return m_logbook.GetTotalDistance();
}

void Vehicle::AddNewLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance) {
	//create the struct Date by the given data
	Logbook::Date date = CreateDate(day, month, year);
	//add new entry, set date and distance
	m_logbook.AddNewEntry(date, distance);
}

void Vehicle::ChangeLastLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance) {
	//create the struct Date by the given data
	Logbook::Date date = CreateDate(day, month, year);
	//renew entry, set new date and new distance
	m_logbook.ChangeLastEntry(date, distance);
}

Logbook::Date Vehicle::CreateDate(size_t const& day, size_t const& month, size_t const& year) {
	Logbook::Date date;
	date.day = 0;
	date.month = 0;
	date.year = 0;

	try {
		//check if day is between 1 and 31
		if (day <= 0 && day > m_daysPerMonth) {
			throw exception("Wrong Date: Your day is not valid");
		}
		//check if month is between 1 and 12
		if (month <= 0 && month > m_monthPerYear) {
			throw exception("Wrong Date: Your month is not valid");
		}
		//check if year is not negativ
		if (year < 0) {
			throw exception("Wrong Date: Your year is not valid");
		}

		//check if the new date is not in the future
		if (year == m_currentYear) {
			if (month > m_currentMonth) {
				throw exception("Wrong Date: Back to the Future?");
			}
			else if (month == m_currentMonth) {
				if (day > m_currentDay) {
					throw exception("Wrong Date: Back to the Future?");
				}
			}
		}
		else if (year > m_currentYear) {
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
	tm ltm;
	localtime_s(&ltm, &now);

	//calculate the current year
	m_currentYear = ltm.tm_year + 1900;
	//calculate the current month
	m_currentMonth = 1 + ltm.tm_mon;
	//gets the current day
	m_currentDay = ltm.tm_mday;
}
