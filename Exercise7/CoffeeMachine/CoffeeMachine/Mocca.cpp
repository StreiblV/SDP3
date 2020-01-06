/* ______________________________________________________________________
| Workfile : Mocca.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Mocca.h"

using namespace pricelist;

std::string Mocca::GetName() {
	return "Mocca";
}

std::string Mocca::GetDescription() {
	std::string desc = "";

	return desc;
}

double Mocca::GetCost() {
	double price = coffee::mocca;

	return price;
}