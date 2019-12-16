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
#include "FileSystem.h"

void FileSystem::Add(std::string const&path, std::shared_ptr<Type> what) {
	try {
		std::string::const_iterator pos1 = std::find(path.cbegin(), path.cend(), "/");
		std::string::const_iterator pos = path.cbegin();
		std::string partOfPath;

		Type::cIterItems cItem;
		Type::pType spType = m_root;

		++pos;

		if (pos1++ != path.cbegin()) {
			throw std::exception("Path needs to begin with a '/'!");
		}

		std::find(pos1, path.cend(), "/");
		while (pos1 != path.cend()) {
			partOfPath.assign(pos, ++pos1);
			pos = pos1;
			cItem = std::find(spType->GetBegin(), spType->GetEnd(), partOfPath);
			if (cItem == spType->GetEnd()||(*cItem)->GetType() != eType::FOLDER) {
				throw std::exception("Invalid Path!");
			}

			spType = *cItem;
			pos1 = std::find(pos1, path.cend(), "/");
		}
		spType->AddItem(what);

	}
	catch (std::exception const& ex) {
		std::cerr << "Error while adding File: " << ex.what() << std::endl;
	}
}
