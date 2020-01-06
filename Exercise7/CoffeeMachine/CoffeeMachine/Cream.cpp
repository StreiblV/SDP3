/* ______________________________________________________________________
| Workfile : Cream.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Cream.h"

using namespace pricelist;

std::string Cream::GetName() {
	return "Cream";
}
double Cream::GetCost() {
	return ingredients::cream;
}
