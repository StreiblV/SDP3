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
	Motorcycle();
	Motorcycle(std::string const& brand, std::string const& numberplate, Fuel fuel);
	virtual ~Motorcycle();
	virtual std::ostream& Print(std::ostream& ost) override;
	virtual std::unique_ptr<Vehicle> Clone() override;
};

#endif //MOTORCYCLE