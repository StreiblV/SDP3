/* ______________________________________________________________________
| Workfile : SojaMilk.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef SOJAMILK_H
#define SOJAMILK_H

#include <string>
#include <memory>

#include "Pricelist.h"
#include "Ingredient.h"

class SojaMilk : public Ingredient {

public:
	SojaMilk(std::shared_ptr<Coffeemachine> const& currCoffee) : Ingredient{ currCoffee } {}

	std::string GetDescription() override;
	double GetCost() override;
};

#endif //!SOJAMILK_H

