/* ______________________________________________________________________
| Workfile : FileSystem.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 09.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "Type.h"
#include "Object.h"

#include <string>
#include <memory>



class FileSystem : public Object{
public:
	FileSystem(std::shared_ptr<Type> root) : m_root{ root } {}
	void Add(std::string const& path, std::shared_ptr<Type> what);

	void VisitAll(IVisitor& v);

	Type::pType GoToPath(std::string const& path) const;
private:
	std::shared_ptr<Type> m_root;

	void VisitRecursive(IVisitor& v, std::shared_ptr<Type>& t);
};

#endif //!FILESYSTEM_H

