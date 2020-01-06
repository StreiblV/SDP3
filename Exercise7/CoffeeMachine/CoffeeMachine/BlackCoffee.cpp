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

std::string BlackCoffee::GetName() {
	return "Black Coffee";
}

std::string BlackCoffee::GetDescription() {
	std::string desc = "";

	return desc;
}

double BlackCoffee::GetCost() {
	double price = coffee::blackcoffee;

	return price;
}
