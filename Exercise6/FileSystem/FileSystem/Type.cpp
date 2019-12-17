/* ______________________________________________________________________
| Workfile : Type.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Type.h"

std::string Type::GetName() const {
	return m_name;
}

void Type::SetPrev(Type* const& to) {
	m_prev = to;
}

Type* Type::GetPrev() const {
	return m_prev;
}

