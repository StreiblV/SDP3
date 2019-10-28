/*______________________________________________________________________
|Workfile:		Carpool.cpp
|Description:	Manages main functionality of the Carpool
|Name:			Weyrer Daniel							PKZ: S1820306044
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/


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
	Carpool();
	~Carpool();
	Carpool(Carpool const& toCopy);
	void Add(Vehicle vehicle);
	void Add(std::string const& brand, std::string const& numberplate, Fuel fuel);
	void Remove(std::string const& numberplate);
	void AddLogbookEntry(std::string const& numberplate, std::string const& date, int const distance);
	void ChangeLastLogbookEntry(std::string const& numberplate, std::string const& date, int const distance);
	
	void SearchByNumberplate(std::string const& numberplate);
	
	
	void PrintVehicles();
	unsigned long TotalMileage() const;

	Carpool& operator =(Carpool const& toCopy);

private:
	std::vector<Vehicle> mVehicles;

	VehicleItor FindVehicle(std::string const& numberplate);

};

#endif //CARPOOL_H
