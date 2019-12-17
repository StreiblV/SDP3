/* ______________________________________________________________________
| Workfile : File.cpp
| Description : [ SOURCE ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#include "File.h"

void File::Accept(IVisitor& v) {
	v.Visit(*this);
}

Type::IterItems File::GetBegin() {
	return IterItems();
}

Type::cIterItems File::GetcBegin() const {
	return Type::cIterItems();
}

Type::cIterItems File::GetcEnd() const {
	return Type::cIterItems();
}

size_t File::GetSize() const {
	return m_size;
}

eType File::GetType() const {
	return eType::FILE;
}

void File::AddItem(std::shared_ptr<Type> const& item) {
	std::cerr << "You Cannot Add a Object to a File!" << std::endl;
}

void File::Write(size_t const bytes) {
	if (bytes > (m_blockSize * m_numberOfBlocks) - m_size) {
		std::cerr << "Write not possible - File is not big enough!" << std::endl;
	}
	else {
		m_size += bytes;
	}
}
