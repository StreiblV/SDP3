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
	//CTor & DTor
	Carpool();
	~Carpool();
	//Copy-CTor
	Carpool(Carpool const& toCopy);

	//Addfunctions to add derived classes to container
	void AddCar(std::string const& brand, std::string const& numberplate, Fuel fuel);
	void AddTruck(std::string const& brand, std::string const& numberplate, Fuel fuel);
	void AddMotorcycle(std::string const& brand, std::string const& numberplate, Fuel fuel);

	//Removes Vehicle with the given numberplate
	void Remove(std::string const& numberplate);

	//Adds one entry in the logbook of the vehicle with the given numberplate
	void AddLogbookEntry(std::string const& numberplate, int const& day, int const& month, int const& year, int const distance);

	//Deletes current last entry in the logbook of the vehicle with the given numberplate and replaces it with the new val given
	void ChangeLastLogbookEntry(std::string const& numberplate, int const& day, int const& month, int const& year, int const distance);
	
	//Searches the vehicle with the given numberplate and Prints its data (if found)
	//or throws an exception when there is no such numberplate in the database
	void SearchByNumberplate(std::string const& numberplate);

	//Adds tge total mileages of every single vehicle in the current pool
	unsigned long TotalMileage() const;

	//Overloaded assignment- and outputoperator
	Carpool& operator =(Carpool const& toCopy);
	
	friend std::ostream& operator<<(std::ostream& ost, Carpool const& c);

private:
	//Stores all vehicles
	TVehicles mVehicles;

	//Helper functions
	void Add(TUptr v);
	VehicleItor FindVehicle(std::string const& numberplate);

};

#endif //CARPOOL_H
