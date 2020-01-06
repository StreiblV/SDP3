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

Sugar::Sugar(std::shared_ptr<Coffeemachine> const& currCoffee) {
	try {
		m_coffee = currCoffee;
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception while adding Cream!" << std::endl;
	}
}

std::string Sugar::GetDescription() {
	return this->m_coffee->GetDescription() + "Sugar";
}
double Sugar::GetCost() {
	return this->m_coffee->GetCost() + ingredients::sugar;
}
