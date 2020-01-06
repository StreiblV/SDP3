/* ______________________________________________________________________
| Workfile : Sugar.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef SUGAR_H
#define SUGAR_H

#include <string>
#include <memory>

#include "Pricelist.h"
#include "Ingredient.h"

class Sugar : public Ingredient {

	Sugar(std::shared_ptr<Coffeemachine> const& currCoffee);
	std::string GetDescription() override;
	double GetCost() override;
};

#endif //!SUGAR_H
