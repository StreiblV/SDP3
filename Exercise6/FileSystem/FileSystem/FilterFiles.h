/* ______________________________________________________________________
| Workfile : FilterFiles.h
| Description : [ HEADER ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 16.12.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef FILTERFILES_H
#define FILTERFILES_H

#include "IVisitor.h"

#include "File.h"
#include "Folder.h"
#include "Referral.h"

class FilterFiles :	public IVisitor {
public:
	void Visit(File& type) override;
	void Visit(Folder& type) override;
	void Visit(Referral& type) override;

private:
};

#endif //!FILTERFILES_H

