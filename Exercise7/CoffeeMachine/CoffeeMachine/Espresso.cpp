/* ______________________________________________________________________
| Workfile : Espresso.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Espresso.h"

using namespace pricelist;

std::string Espresso::GetDescription() {
	return "Espresso";
}

double Espresso::GetCost() {
	double price = coffee::espresso;

	return price;
}