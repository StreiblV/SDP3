/* ______________________________________________________________________
| Workfile : Coffeemachine.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include <iostream>
#include "Coffeemachine.h"



void Coffeemachine::GetDisplay() {
}

void Coffeemachine::SetName(std::string const& name) {
	m_name = name;
}

std::string Coffeemachine::GetName() const {
	return m_name;
}
