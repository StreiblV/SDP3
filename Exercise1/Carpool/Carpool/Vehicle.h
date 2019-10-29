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

//fuel types of vehicle
enum class Fuel { Petrol, Diesel, Gas, Electricity };

class Vehicle
{
public:
	//general print method
	virtual std::ostream& Print(std::ostream& ost) = 0;
	//general clone method
	virtual std::unique_ptr<Vehicle> Clone() = 0;

	//constructor
	Vehicle();
	//deconstructor
	virtual ~Vehicle();

	//return numberplate of vehicle
	std::string GetNumberplate();
	//return driven kilometers of vehicle
	unsigned long GetMileage() const;

	//set brand of vehicle
	void SetBrand(std::string brand);
	//set numerplate of vehicle
	void SetNumberplate(std::string numberplate);
	//set fuel type of vehicle
	void SetFuel(Fuel fuel);

	//add a new logbook entry
	void AddNewLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance);

	//change the last logbook entry
	void ChangeLastLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance);

	Vehicle& operator=(Vehicle const& toCopy);

protected:
	std::string m_brand;
	std::string m_numberplate;
	Fuel m_fuel;

	//print all vehicles
	std::ostream& PrintList(std::ostream& ost);

private:
	Logbook m_logbook;
	int const m_monthPerYear = 12;
	int const m_daysPerMonth = 31;

	int m_currentDay = 0;
	int m_currentMonth = 0;
	int m_currentYear = 0;

	//create the struct Date by the given variables
	Logbook::Date CreateDate(size_t const& day, size_t const& month, size_t const& year);
	//get the current date
	void setCurrentDate();
};

#endif //VEHICLES
