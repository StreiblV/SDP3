#ifndef CARPOOL_H
#include "Vehicle.h"

#include <iostream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>
#include <string>
#include <vector>

typedef std::vector<Vehicle>::const_iterator VehicleCItor;

class Carpool{
public:
	void Add(Vehicle vehicle);
	void Add(std::string const& numberplate, std::string const& brand, Vehicle::Fuel fuel);
	//TODO:	Add ohne Vehicle anlegen sondern (evlt zusätzlich?) mit nur namen, nummertafel etc.
	// Add(std::string brand, std::string numberplate, Fuel fuel)
	void Remove(std::string const& numberplate);
	void SearchByNumberplate(std::string const& numberplate);
	unsigned long TotalMileage() const;

private:
	std::vector<Vehicle> mVehicles;

	VehicleCItor FindVehicle(std::string const& numberplate) const;

};

#endif //CARPOOL_H
