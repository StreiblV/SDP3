/* ______________________________________________________________________
| Workfile : SojaMilk.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "SojaMilk.h"

#include <iostream>

using namespace pricelist;


std::string SojaMilk::GetDescription() {
	return Ingredient::GetDescription() + " SojaMilk ";
}

double SojaMilk::GetCost() {
	return Ingredient::GetCost() + ingredients::sojaMilk;
}
