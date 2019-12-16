/* ______________________________________________________________________
| Workfile : Referral.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Referral.h"

void Referral::Accept(IVisitor& v) {
	//v.Visit(*this);
}

Type::cIterItems Referral::GetBegin() const {
	return Type::cIterItems();
}

Type::cIterItems Referral::GetEnd() const {
	return cIterItems();
}

void Referral::AddItem(std::shared_ptr<Type> item) {}

eType Referral::GetType() const {
	return eType::REFERRAL;
}
