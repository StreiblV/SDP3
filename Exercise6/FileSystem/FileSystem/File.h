/* ______________________________________________________________________
| Workfile : File.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef FILE_H
#define FILE_H

#include "Type.h"


class File : public Type {
public:
	File(size_t const blockSize, size_t const numberOfBlocks) : 
		m_size{ blockSize * numberOfBlocks },
		m_blockSize{ blockSize }, 
		m_numberOfBlocks(numberOfBlocks) {}

	virtual void Accept(IVisitor& v) override;

	virtual cIterItems GetBegin() const override;
	virtual cIterItems GetEnd() const override;

	virtual eType GetType() const override;
	virtual void AddItem(std::shared_ptr<Type> item) override;



private:
	size_t m_size;
	size_t m_blockSize;
	size_t m_numberOfBlocks;
};

#endif //!FILE_H
