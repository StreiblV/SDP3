/*______________________________________________________________________
|Workfile:		Motorcycle.h
|Description:	[HEADER] Class for a Vehicle of type Motorcycle
|Name:			Viktoria Streibl						PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#ifndef MOTORCYCLE
#define MOTORCYCLE

#include "Vehicle.h"
class Motorcycle : public Vehicle
{
public:
	//constructor
	Motorcycle();
	//create a new motorcycle
	Motorcycle(std::string const& brand, std::string const& numberplate, Fuel fuel);
	//deconstrcutor
	virtual ~Motorcycle();
	//Prints the brand, type, numberplate and logbook dat
	virtual std::ostream& Print(std::ostream& ost) override;
	//clone motorcycle
	virtual std::unique_ptr<Vehicle> Clone() override;
};

#endif //MOTORCYCLE