/* ______________________________________________________________________
| Workfile : Milk.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef MILK_H
#define MILK_H

#include <string>
#include <memory>

#include "Pricelist.h"
#include "Ingredient.h"

class Milk : public Ingredient {
public:
	Milk(std::shared_ptr<Coffeemachine> const& currCoffee) : Ingredient{ currCoffee } {}

	std::string GetDescription() override;
	double GetCost() override;
};

#endif //!MILK_H

