/* ______________________________________________________________________
| Workfile : FilterFiles.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "FilterFiles.h"

void FilterFiles::Visit(File& type) {
	FindFirstElement(type);
	//Filter Data by size
	FilterBySize(*m_root);
}

void FilterFiles::Visit(Folder& type) {
	FindFirstElement(type);
	//Filter Data by size
	FilterBySize(*m_root);

	//Filter Referral
	FilterByReferral(*m_root);
}

void FilterFiles::Visit(Referral& type) {
	FindFirstElement(type);
	//Filter Referral
	FilterByReferral(*m_root);
}

void FilterFiles::SetMinSize(int minSize) {
	m_minSize = minSize;
}
void FilterFiles::SetMaxSize(int maxSize) {
	m_maxSize = maxSize;
}

std::string FilterFiles::GetPath(Type& const type) {
	bool isRoot = false;
	Type* currentType = &type;

	std::string path = "";

	//loop until find root
	while (!isRoot) {
		currentType = currentType->GetPrev();

		if (currentType == nullptr) {
			isRoot = true;
		}
		else {
			path = currentType->GetName() + "/" + path;
		}
	}
	return path;
}

void FilterFiles::FindFirstElement(Type& const type) {
	bool isRoot = false;
	Type* currentType = &type;

	//loop until find root
	while (!isRoot) {
		currentType = currentType->GetPrev();

		//check if root
		if (currentType == nullptr) {
			isRoot = true;
			m_root = &type;
		}
	}
}
void FilterFiles::FilterBySize(Type& const type) {
	//check for filetype
	if (type.GetType() == eType::FOLDER) {
		//loop through folder
		Type::cIterItems currentItem = type.GetBegin();
		while (currentItem != type.GetcEnd()) {
			FilterBySize(*(*currentItem));
			currentItem++;
		}
	}
	else if (type.GetType() == eType::REFERRAL) {
		FilterBySize(*(*type.GetBegin()));
	}
	//print file and referral
	else if (type.GetType() == eType::FILE) {
		File file = dynamic_cast<File&>(type);
		size_t size = file.GetSize();

		if (size >= m_minSize && size <= m_maxSize) {
			Print(type);
		}
	}
}

void FilterFiles::FilterByReferral(Type& const type) {
	//check for filetype
	if (type.GetType() == eType::FOLDER) {
		//loop through folder
		Type::cIterItems currentItem = type.GetBegin();
		while (currentItem != type.GetcEnd()) {
			FilterBySize(*(*currentItem));
			currentItem++;
		}
	}
	//print file and referral
	else if (type.GetType() == eType::REFERRAL) {
		Print(type);
	}
}

void FilterFiles::Print(Type& const type) {
	Type* prevType = type.GetPrev();
	std::string path = GetPath(*prevType);
	std::cout << path << "/" << type.GetName();
}