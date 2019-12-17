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

Type::IterItems Folder::GetBegin() {
	return m_items.begin();
}

Type::cIterItems Folder::GetcBegin() const {
	return (m_items.cbegin());
}

Type::cIterItems Folder::GetcEnd() const {
	return m_items.cend();
}



eType Folder::GetType() const {
	return eType::FOLDER;
}

void Folder::AddItem(std::shared_ptr<Type> const& item) {
	//Add Item if it`s not a nullptr
	if (item != nullptr){

		if (std::find(m_items.cbegin(), m_items.cend(), item) == m_items.cend()) {

			m_items.emplace_back(item);
			item->SetPrev(this);
		}
		else {
			std::cerr << "Error: Duplicate!" << std::endl;
		}
	}
	else {
		std::cerr << "Error while Adding Item" << std::endl;
	}
}
