/*______________________________________________________________________
|Workfile:		Vehicles.h
|Description:	[HEADER] Base Class for different Vehicletypes
|Name:			Viktoria Streibl				PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#ifndef VEHICLES

#include "Logbook.h"
#include <string>
#include <list>

enum class Fuel { Petrol, Diesel, Gas, Electricity };

class Vehicle
{
public:
	virtual void Print(){};

	Vehicle();
	Vehicle(std::string brand, std::string numberplate, Fuel fuel);
	virtual ~Vehicle();

	std::string GetNumberplate();
	unsigned long GetMileage() const;

	void SetBrand(std::string brand);
	void SetNumberplate(std::string numberplate);
	void SetFuel(Fuel fuel);

	void AddNewLogbookEntry(std::string const& date, int const& distance);
	void ChangeLastLogbookEntry(std::string const& date, int const& distance);

	bool operator == (Vehicle const& x) const;

protected:
	std::string m_brand;
	std::string m_numberplate;
	Fuel m_fuel;

	void PrintList();

private:
	Logbook m_logbook;
};

#endif //VEHICLES
