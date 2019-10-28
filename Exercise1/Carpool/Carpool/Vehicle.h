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

	void SetBrand(std::string brand);
	void SetNumberplate(std::string numberplate);
	void SetFuel(Fuel fuel);
	unsigned long GetMileage() const;

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
