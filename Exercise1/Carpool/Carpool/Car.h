#ifndef CAR

#include "Vehicle.h"

class Car : public Vehicle
{
public:
	virtual ~Car();
	virtual void Print() override;
};
#endif // CAR

