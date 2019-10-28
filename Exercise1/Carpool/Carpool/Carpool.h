#ifndef CARPOOL_H
#include "Vehicle.h"

#include <iostream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>
#include <string>
#include <vector>

typedef std::vector<Vehicle>::iterator VehicleItor;

class Carpool{
public:
	void Add(Vehicle vehicle);
	void Add(std::string const& brand, std::string const& numberplate, Fuel fuel);
	void Remove(std::string const& numberplate);
	void SearchByNumberplate(std::string const& numberplate);
	unsigned long TotalMileage() const;

private:
	std::vector<Vehicle> mVehicles;

	VehicleItor FindVehicle(std::string const& numberplate);

};

#endif //CARPOOL_H
