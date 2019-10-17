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
	void Add(Vehicle const& vehicle);
	void Remove(std::string const& numberplate);
	void SearchVehicle(std::string const& numberplate);
	unsigned long TotalMileage() const;

private:
	std::vector<Vehicle> mVehicles;

	VehicleCItor FindVehicle(std::string const& numberplate) const;

};

#endif //CARPOOL_H