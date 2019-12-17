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
	currentDepth = 0;
	PrintCurrentElement(outputType, type.GetName());
}

void Dump::Visit(Folder& type) {
	//get first element
	currentDepth = 0;
}

void Dump::Visit(Referral& type) {
	//get first element
	currentDepth = 0;
}

void Dump::PrintCurrentElement(std::ostream& out, std::string const filename) {
	for (int i = 0; i < currentDepth; i++) {
		out << " ";
	}
	out << filename;
}

void Dump::FindFirstElement(Type& const type) {
	bool isRoot = false;
	while (isRoot) {

	}
}

void Dump::ReadCurrentPath(Type& type) {
	//check for filetype
	if (type.GetType() == eType::REFERRAL) {
		ReadCurrentPath(*(*(type.GetBegin())));
	}
	else if (type.GetType() == eType::FOLDER) {
		PrintCurrentElement(outputType, type.GetName());

		//loop through folder
		Type::cIterItems currentItem = type.GetBegin();
		while (currentItem != type.GetEnd()) {
			if ((*currentItem)->GetType() == eType::FOLDER) {
				currentDepth++;
				ReadCurrentPath(*(*currentItem));
				currentDepth--;
			}
			else {
				ReadCurrentPath(*(*currentItem));
			}
		}
	}
	else {
		PrintCurrentElement(outputType, type.GetName());
	}
}
