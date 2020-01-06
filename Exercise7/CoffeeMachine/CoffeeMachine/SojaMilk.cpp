/* ______________________________________________________________________
| Workfile : SojaMilk.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "SojaMilk.h"

#include <iostream>

using namespace pricelist;

SojaMilk::SojaMilk(std::shared_ptr<Coffeemachine> const& currCoffee) {
	try {
		m_coffee = currCoffee;
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception while adding Cream!" << ex.what() << std::endl;
	}
}

std::string SojaMilk::GetDescription() {
	return this->m_coffee->GetDescription() + "SojaMilk";
}
double SojaMilk::GetCost() {
	return this->m_coffee->GetCost() + ingredients::sojaMilk;
}
