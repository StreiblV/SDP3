/* ______________________________________________________________________
| Workfile : Sugar.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Sugar.h"
#include <iostream>

using namespace pricelist;

std::string Sugar::GetDescription() {
	return Ingredient::GetDescription() + " Sugar ";
}
double Sugar::GetCost() {
	return Ingredient::GetCost() + ingredients::sugar;
}
