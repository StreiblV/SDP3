/* ______________________________________________________________________
| Workfile : Dump.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "Dump.h"

void Dump::Visit(File& type) {
	//get first element
	FindFirstElement(type);

	Visit();
}

void Dump::Visit(Folder& type) {
	//get first element
	FindFirstElement(type);

	Visit();
}

void Dump::Visit(Referral& type) {
	//get first element
	FindFirstElement(type);

	Visit();
}

void Dump::Visit() {
	m_currentDepth = 0;

	//loop through everything and print it
	ReadCurrentPath(*m_root);

}
void Dump::PrintCurrentElement(std::ostream& out, std::string const filename) {
	for (int i = 0; i < m_currentDepth; i++) {
		out << " ";
	}
	out << filename;
}

void Dump::FindFirstElement(Type& const type) {
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

void Dump::ReadCurrentPath(Type& type) {
	//check for filetype
	if (type.GetType() == eType::FOLDER) {
		PrintCurrentElement(m_outputType, type.GetName());

		//loop through folder
		Type::cIterItems currentItem = type.GetcBegin();
		while (currentItem != type.GetcEnd()) {
			//check if current item is folder
			if ((*currentItem)->GetType() == eType::FOLDER) {
				//increase structur depth
				m_currentDepth++;
				//call this method again with new folder-path
				ReadCurrentPath(*(*currentItem));
				//decrease structur depth
				m_currentDepth--;
			}
			//call if folder, referall or other
			else {
				ReadCurrentPath(*(*currentItem));
			}
			currentItem++;
		}
	}
	//print file and referral
	else {
		PrintCurrentElement(m_outputType, type.GetName());
	}
}
