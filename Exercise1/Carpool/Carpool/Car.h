/*______________________________________________________________________
|Workfile:		Car.h
|Description:	[HEADER] Class for a Vehicle of type Car
|Name:			Viktoria Streibl						PKZ: S1810306013
|Date:			28.10.2019
|Remarks:		-
|Revision:		0
|_______________________________________________________________________*/

#ifndef CAR
#define CAR

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	Car(std::string const& brand, std::string const& numberplate, Fuel fuel);
	virtual ~Car();
	virtual std::ostream& Print(std::ostream& ost) override;
	virtual std::unique_ptr<Vehicle> Clone() override;
};
#endif // CAR

