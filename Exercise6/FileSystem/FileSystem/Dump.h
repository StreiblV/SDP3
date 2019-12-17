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

#include "File.h"
#include "Folder.h"
#include "Referral.h"

class Dump : public IVisitor {
public:
	void Visit(File& type) override;
	void Visit(Folder& type) override;
	void Visit(Referral& type) override;

private:
	int currentDepth = 0;
	std::ostream& outputType = std::cout;

	void PrintCurrentElement(std::ostream& out, std::string const filename);
	void FindFirstElement(Type& const type);
	void ReadCurrentPath(Type& const type);
};

#endif //!DUMP_H