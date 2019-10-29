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
	Truck();
	Truck(std::string const& brand, std::string const& numberplate, Fuel fuel);
	virtual ~Truck();
	virtual std::ostream& Print(std::ostream& ost) override;
	virtual std::unique_ptr<Vehicle> Clone() override;
};

#endif // TRUCK