/* ______________________________________________________________________
| Workfile : BlackCoffee.h
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "BlackCoffee.h"

using namespace pricelist;

std::string BlackCoffee::GetDescription() {
	return "Black Coffee";
}

double BlackCoffee::GetCost() {
	double price = coffee::blackcoffee;

	return price;
}
