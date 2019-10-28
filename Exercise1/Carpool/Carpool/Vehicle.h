#ifndef VEHICLES

#include "Logbook.h"
#include <string>
#include <list>
#include <ctime>

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

	void AddNewLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance);
	void ChangeLastLogbookEntry(size_t const& day, size_t const& month, size_t const& year, int const& distance);

protected:
	std::string m_brand;
	std::string m_numberplate;
	Fuel m_fuel;

	void PrintList();

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
