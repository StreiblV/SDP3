/*______________________________________________________________________
|Workfile:		Vehicles.h
|Description:	[HEADER] Base Class for different Vehicletypes
|Name:			Viktoria Streibl				PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#ifndef VEHICLES
#define VEHICLES

#include "Logbook.h"
#include <string>
#include <list>
#include <time.h>

enum class Fuel { Petrol, Diesel, Gas, Electricity };

class Vehicle
{
public:
	virtual std::ostream& Print(std::ostream& ost) = 0;
	virtual std::unique_ptr<Vehicle> Clone() = 0;

	Vehicle();
	virtual ~Vehicle();

	std::string GetNumberplate();
	unsigned long GetMileage() const;

	void SetBrand(std::string brand);
	void SetNumberplate(std::string numberplate);
	void SetFuel(Fuel fuel);

	void AddNewLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance);
	void ChangeLastLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance);

	Vehicle& operator=(Vehicle const& toCopy);

protected:
	std::string m_brand;
	std::string m_numberplate;
	Fuel m_fuel;

	std::ostream& PrintList(std::ostream& ost);

private:
	Logbook m_logbook;
	int const m_monthPerYear = 12;
	int const m_daysPerMonth = 31;

	int m_currentDay = 0;
	int m_currentMonth = 0;
	int m_currentYear = 0;

	Logbook::Date CreateDate(size_t const& day, size_t const& month, size_t const& year);
	void setCurrentDate();
};

#endif //VEHICLES
