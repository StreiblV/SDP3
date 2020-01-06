/* ______________________________________________________________________
| Workfile : Sugar.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Sugar.h"

using namespace pricelist;

std::string Sugar::GetName() {
	return "Sugar";
}
double Sugar::GetCost() {
	return ingredients::sugar;
}
