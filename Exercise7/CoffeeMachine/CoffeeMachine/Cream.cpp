/* ______________________________________________________________________
| Workfile : Cream.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Cream.h"
#include <iostream>

using namespace pricelist;

std::string Cream::GetDescription() {
	return Ingredient::GetDescription() + " Cream ";
}
double Cream::GetCost() {
	return Ingredient::GetCost() + ingredients::cream;
}
