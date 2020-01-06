/* ______________________________________________________________________
| Workfile : Mocca.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef COFFEE_H
#define COFFEE_H

#include <string>

#include "Pricelist.h"
#include "Coffeemachine.h"

class Mocca : public Coffeemachine{

	std::string GetDescription() override;
	double GetCost() override;
};

#endif //!COFFEE_H
