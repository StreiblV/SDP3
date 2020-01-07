/* ______________________________________________________________________
| Workfile : Cream.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef CREAM_H
#define CREAM_H

#include <string>

#include "Pricelist.h"
#include "Ingredient.h"

class Cream : public Ingredient {
public:
	Cream(std::shared_ptr<Coffeemachine> const& currCoffee) : Ingredient{ currCoffee } {}

	std::string GetDescription() override;
	double GetCost() override;
};

#endif //!CREAM_H

