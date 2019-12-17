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
	m_ref = to;
}

void Referral::Accept(IVisitor& v) {
	v.Visit(*this);
}

Type::IterItems Referral::GetBegin() {
	return m_ref->GetBegin();
}

Type::cIterItems Referral::GetcBegin() const {
	return m_ref->GetBegin();
}

Type::cIterItems Referral::GetcEnd() const {
	return m_ref->GetcEnd();
}

void Referral::AddItem(std::shared_ptr<Type> const& item) {
	item->AddItem(item);
}

eType Referral::GetType() const {
	return eType::REFERRAL;
}
