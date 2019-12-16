/* ______________________________________________________________________
| Workfile : IVisitor.h
| Description : [ HEADER ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef IVISITOR_H
#define IVISITOR_H

#include "File.h"
#include "Folder.h"
#include "Referral.h"

class IVisitor {
	virtual void Visit(File& type) = 0;
	virtual void Visit(Folder& type) = 0;
	virtual void Visit(Referral& type) = 0;
	virtual ~IVisitor() = default;
};

#endif //!IVISITOR_H

