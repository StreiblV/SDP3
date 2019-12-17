/* ______________________________________________________________________
| Workfile : FileSystem.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include <iostream>
#include <algorithm>
#include "FileSystem.h"

bool operator== (std::shared_ptr<Type> const& lhs, std::string const& rhs) {
	return (lhs->GetName() == rhs);
}

void FileSystem::Add(std::string const& path, std::shared_ptr<Type> what) {
	try {
		Type::pType spType;

		//Get Item from Path
		spType = GoToPath(path);
		//Add Item at specific location
		spType->AddItem(what);
	}

	catch (std::exception const& ex) {
		std::cerr << "Error while adding File: " << ex.what() << std::endl;
	}
}

void FileSystem::VisitAll(IVisitor& v) {
	VisitRecursive(v, m_root);
}

Type::pType FileSystem::GoToPath(std::string const& path) const {
	std::string::const_iterator pos1{ std::find(path.cbegin(), path.cend(), '/') };
	std::string::const_iterator pos = path.cbegin();
	std::string partOfPath;

	Type::cIterItems cItem;
	Type::pType spType = m_root;

	//check if path starts with a slash
	if (pos1++ != path.cbegin()) {
		throw std::exception("Path needs to begin with a '/'!");
	}
	//stay in root when there`s just a slash
	if (path.size() != 1) {
		//get name of the given directory
		pos1 = std::find(pos1, path.cend(), '/');

		//loop through path and stop at the end of path string
		while (pos1 != path.cend()) {
			partOfPath.assign(++pos, pos1);
			pos = pos1;
			cItem = std::find(spType->GetcBegin(), spType->GetcEnd(), partOfPath);

			if (cItem == spType->GetcEnd() || (*cItem)->GetType() != eType::FOLDER) {
				throw std::exception("Invalid Path!");
			}

			partOfPath.clear();
			spType = *cItem;

			pos1 = std::find(++pos1, path.cend(), '/');
		}
	}
	return spType;
}

void FileSystem::VisitRecursive(IVisitor& v, std::shared_ptr<Type>& f) {
	Type::cIterItems iter = f->GetcBegin();
	size_t max = std::distance(iter, f->GetcEnd());
	Type::IterItems pos = f->GetBegin();

	for (size_t i = 0; i < max; i++) {
		if ((*pos)->GetType() == eType::FILE) {
			(*pos)->Accept(v);
		}
		if ((*pos)->GetType() == eType::FOLDER) {
			VisitRecursive(v, (*pos));
		}
		advance(pos, 1);
	}
}
