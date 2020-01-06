/* ______________________________________________________________________
| Workfile : SojaMilk.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "SojaMilk.h"

std::string SojaMilk::GetName() {
	return "Soja-Milk";
}
double SojaMilk::GetCost() {
	return pricelist::sojaMilk;
}
