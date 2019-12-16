/* ______________________________________________________________________
| Workfile : Dump.h
| Description : [ HEADER ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef DUMP_H
#define DUMP_H

#include "IVisitor.h"

class Dump : public IVisitor {
public:
	void Visit(File& type) override;
	void Visit(Folder& type) override;
	void Visit(Referral& type) override;

private:
};

#endif //!DUMP_H

