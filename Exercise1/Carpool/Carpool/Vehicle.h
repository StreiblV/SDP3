#ifndef VEHICLES

#include "Logbook.h"
#include <string>
#include <list>

class Vehicle
{
public:
	enum class Fuel { Petrol, Diesel, Gas, Electricity };

	virtual void Print() = 0;

	Vehicle();
	Vehicle(std::string brand, std::string numberplate, Fuel fuel);
	virtual ~Vehicle();

	std::string GetNumberplate();

	void SetBrand(std::string brand);
	void SetNumberplate(std::string numberplate);
	void SetFuel(Fuel fuel);

protected:
	std::string m_brand;
	std::string m_numberplate;
	Fuel m_fuel;

	void PrintList();

private:
	Logbook m_logbook;
};

#endif //VEHICLES