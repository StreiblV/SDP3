/* ______________________________________________________________________
| Workfile : Referral.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Referral.h"

Referral::Referral(std::shared_ptr<Type> const& to, std::string const& name) {
	m_name = name;
	//set_to;
}

void Referral::Accept(IVisitor& v) {
	v.Visit(*this);
}

Type::cIterItems Referral::GetBegin() const {
	return m_ref->GetBegin();
}

Type::cIterItems Referral::GetEnd() const {
	return m_ref->GetEnd();
}

void Referral::AddItem(std::shared_ptr<Type> const& item) {
	item->AddItem(item);
}

eType Referral::GetType() const {
	return eType::REFERRAL;
}
