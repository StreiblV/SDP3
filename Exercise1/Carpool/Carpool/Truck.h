/*______________________________________________________________________
|Workfile:		Truck.h
|Description:	[HEADER] Class for a Vehicle of type Truck
|Name:			Viktoria Streibl						PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#ifndef TRUCK
#define TRUCK
#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	//constructor
	Truck();
	//create a new truck
	Truck(std::string const& brand, std::string const& numberplate, Fuel fuel);
	//deconstrcutor
	virtual ~Truck();
	//Prints the brand, type, numberplate and logbook dat
	virtual std::ostream& Print(std::ostream& ost) override;
	//clone truck
	virtual std::unique_ptr<Vehicle> Clone() override;
};

#endif // TRUCK