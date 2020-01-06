/* ______________________________________________________________________
| Workfile : Cream.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Cream.h"
#include <iostream>

using namespace pricelist;

Cream::Cream(std::shared_ptr<Coffeemachine> const& currCoffee) {
	try {
		m_coffee = currCoffee;
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception while adding Cream!" << ex.what() << std::endl;
	}
}

std::string Cream::GetDescription() {
	return this->m_coffee->GetDescription() + "Cream";
}
double Cream::GetCost() {
	return this->m_coffee->GetCost() + ingredients::cream;
}
