#ifndef TRUCK
#include "Vehicle.h"

class Truck : public Vehicle
{
public:
	virtual ~Truck();
	virtual void Print() override;
};

#endif // TRUCK