#ifndef MOTORCYCLE
#include "Vehicle.h"
class Motorcycle : public Vehicle
{
public:
	virtual ~Motorcycle();
	virtual void Print() override;
};

#endif //MOTORCYCLE