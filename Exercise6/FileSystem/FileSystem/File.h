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
#include <iostream>

class File : public Type {
public:
	File(size_t const blockSize, size_t const numberOfBlocks, std::string const& name) : 
		m_size{ 0 },
		m_blockSize{ blockSize }, 
		m_numberOfBlocks(numberOfBlocks) { m_name = name; }

	//Visitor_func
	virtual void Accept(IVisitor& v) override;

	//Getters
	size_t GetSize() const;
	virtual eType GetType() const override;


	//Writes the number of bytes to the file if there is enough space
	void Write(size_t const bytes);

	//UNUSED FOR FILES!!!
	virtual cIterItems GetBegin() const override;
	virtual cIterItems GetEnd() const override;
	virtual void AddItem(std::shared_ptr<Type> const& item) override;

private:
	size_t m_size;
	size_t m_blockSize;
	size_t m_numberOfBlocks;
};

#endif //!FILE_H
