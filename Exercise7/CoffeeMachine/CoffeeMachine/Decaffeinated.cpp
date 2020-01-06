/* ______________________________________________________________________
| Workfile : Decaffeinated.cpp 
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Decaffeinated.h"

using namespace pricelist;

std::string Decaffeinated::GetName() {
	return "Decaffeinated";
}

std::string Decaffeinated::GetDescription() {
	std::string desc = "";

	return desc;
}

double Decaffeinated::GetCost() {
	double price = coffee::decaffeinated;

	return price;
}