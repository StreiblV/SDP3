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

#include "Pricelist.h"
#include "Ingredient.h"

class SojaMilk : public Ingredient {
	std::string GetName() override;
	double GetCost() override;
};

#endif //!SOJAMILK_H

