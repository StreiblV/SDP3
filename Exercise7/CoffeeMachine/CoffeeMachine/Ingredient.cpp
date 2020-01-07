/* ______________________________________________________________________
| Workfile : Ingredient.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Ingredient.h"
#include <iostream>

std::string Ingredient::GetDescription() {
	return m_coffee->GetDescription();
}

double Ingredient::GetCost() {
	return m_coffee->GetCost();
}

Ingredient::Ingredient(Coffeemachine::SPtr const& currCoffee) {
	try {
		if (currCoffee == nullptr) {
			throw("Null-pointer!");
		}

		m_coffee = currCoffee;
	}
	catch (std::exception const& ex) {
		std::cerr << "Exception in Ingredient CTor!" << ex.what() << std::endl;
	}
}