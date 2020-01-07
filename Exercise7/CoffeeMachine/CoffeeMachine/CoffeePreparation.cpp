/* ______________________________________________________________________
| Workfile : CoffeePreparation.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "CoffeePreparation.h"

void CoffeePreparation::Prepare(Coffeemachine::SPtr const& coffee) {
	if (coffee != nullptr) {
		m_Ingredients.emplace_front(coffee);
	}
	else {
		std::cerr << "Please check given Parameter - nullptr detected!" << std::endl;
	}
}

void CoffeePreparation::Display(std::ostream& os) {
	if (os.good()) {
		for (auto elem : m_Ingredients) {
			os << elem->GetDescription() << std::endl;
		}
	}
}

void CoffeePreparation::Finished() {
	if (!m_Ingredients.empty()) {
		auto temp = m_Ingredients.back();
		std::cout << temp->GetDescription() << " = " << temp->GetCost() << std::endl;
		m_Ingredients.pop_back();
	}
	else {
		std::cerr << "No Coffee in the list!" << std::endl;
	}
}
