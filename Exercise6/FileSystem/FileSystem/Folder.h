/* ______________________________________________________________________
| Workfile : Folder.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef FOLDER_H
#define FOLDER_H

#include "Type.h"

#include <iostream>
#include <memory>
#include <list>

class Folder : public Type {
public:
	Folder(std::string const& name);

	virtual void Accept(IVisitor& v) override;

	virtual IterItems GetBegin() override;
	virtual cIterItems GetcBegin() const override;
	virtual cIterItems GetcEnd() const override;

	virtual eType GetType() const override;

	virtual void AddItem(std::shared_ptr<Type> const& item) override;
	
private:
	std::list<std::shared_ptr<Type>> m_items;
};

#endif //!FOLDER_H

