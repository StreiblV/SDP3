/* ______________________________________________________________________
| Workfile : Milk.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Milk.h"

using namespace pricelist;

std::string Milk::GetName() {
	return "Milk";
}
double Milk::GetCost() {
	return ingredients::milk;
}
