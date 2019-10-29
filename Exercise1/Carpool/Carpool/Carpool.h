/*______________________________________________________________________
|Workfile:		Carpool.h
|Description:	[HEADER] Main Class managing Carpool-program
|Name:			Daniel Weyrer							PKZ: S1820306044
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#ifndef CARPOOL_H
#define CARPOOL_H

#include "Car.h"
#include "Motorcycle.h"
#include "Truck.h"

#include <iostream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <exception>
#include <string>
#include <vector>
#include <memory>
#include <ostream>

typedef std::unique_ptr<Vehicle> TUptr;
typedef std::vector<TUptr> TVehicles;
typedef TVehicles::iterator VehicleItor;
typedef TVehicles::const_iterator VehicleCItor;


class Carpool{
public:
	Carpool();
	~Carpool();
	Carpool(Carpool const& toCopy);

	void AddCar(std::string const& brand, std::string const& numberplate, Fuel fuel);
	void AddTruck(std::string const& brand, std::string const& numberplate, Fuel fuel);
	void AddMotorcycle(std::string const& brand, std::string const& numberplate, Fuel fuel);

	void Remove(std::string const& numberplate);
	void AddLogbookEntry(std::string const& numberplate, int const& day, int const& month, int const& year, int const distance);
	void ChangeLastLogbookEntry(std::string const& numberplate, int const& day, int const& month, int const& year, int const distance);
	
	void SearchByNumberplate(std::string const& numberplate);

	unsigned long TotalMileage() const;

	Carpool& operator =(Carpool const& toCopy);
	
	friend std::ostream& operator<<(std::ostream& ost, Carpool const& c);

private:
	TVehicles mVehicles;

	void Add(TUptr v);
	VehicleItor FindVehicle(std::string const& numberplate);

};

#endif //CARPOOL_H
