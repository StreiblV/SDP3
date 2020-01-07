/* ______________________________________________________________________
| Workfile : Milk.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Milk.h"

#include <iostream>

using namespace pricelist;

std::string Milk::GetDescription() {
	return Ingredient::GetDescription() + "Milk, ";
}


double Milk::GetCost() {
	return Ingredient::GetCost() + ingredients::milk;
}
