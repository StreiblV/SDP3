/* ______________________________________________________________________
| Workfile : SymbolParser.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "SymbolFactory.h"

void SymbolFactory::AddType(std::string const& name) {
	try {
		if (!m_types.empty()) {
			auto res = std::find(m_types.begin(), m_types.end(), name);

			if (res != m_types.end()) {
				throw TypeAlreadyDefinedException();
			}
		}
		m_types.push_back(name);
	}
	catch (TypeAlreadyDefinedException &e) {
		std::cout << e.what(name) << std::endl;
	}
}

void SymbolFactory::AddVariable(std::string const& name, std::string const& type) {
	try{
		if (!m_types.empty()) {
			auto resType = std::find(m_types.begin(), m_types.end(), type);
			if (resType != m_types.end()) {
				if (!m_variables.empty()) {
					auto resDub = m_variables.begin();
					bool isDub = false;
					for (; resDub != m_variables.end(); resDub++) {
						if ((*resDub).second == name) {
							isDub = true;
						}
					}

					if (isDub) {
						throw VariableAlreadyDefinedException();
					}
				}
				m_variables.push_back(std::make_pair(name, type));
			}
			else {
				throw TypeNotDefinedException();
			}
		}
		else {
			throw TypeNotDefinedException();
		}
	}
	catch (TypeNotDefinedException & e) {
		std::cout << e.what(type) << std::endl;
	}
	catch (VariableAlreadyDefinedException & e) {
		std::cout << e.what(name) << std::endl;
	}
}