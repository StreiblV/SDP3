/* ______________________________________________________________________
| Workfile : Folder.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Folder.h"

Folder::Folder(std::string const& name) {
	m_name = name;
}

void Folder::Accept(IVisitor& v) {
	v.Visit(*this);
}

Type::cIterItems Folder::GetBegin() const {
	return (m_items.cbegin());
}

Type::cIterItems Folder::GetEnd() const {
	return m_items.cend();
}

eType Folder::GetType() const {
	return eType::FOLDER;
}

void Folder::AddItem(std::shared_ptr<Type> const& item) {
	if (item != nullptr){
		m_items.emplace_back(item);
		m_prev = std::make_shared<Folder>(*this);
	}
	else {
		std::cerr << "Error while Adding Item" << std::endl;
	}
}
