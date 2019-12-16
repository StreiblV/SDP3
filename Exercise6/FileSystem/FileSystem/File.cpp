/* ______________________________________________________________________
| Workfile : File.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "File.h"

void File::Accept(IVisitor& v) {
//	v.Visit(*this);
}

Type::cIterItems File::GetBegin() const {
	return Type::cIterItems();
}

Type::cIterItems File::GetEnd() const {
	return Type::cIterItems();
}

eType File::GetType() const {
	return eType::FILE;
}

void File::AddItem(std::shared_ptr<Type> item) {}
