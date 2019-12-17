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

/*
	Implementieren Sie einen Visitor (FilterFiles) der alle Dateien herausfiltert deren aktuelle Größe 
	innerhalb eines vorgegebenen minimalen und maximalen Wertes liegt. Ein zusätzlicher Filter
	soll alle Verweise herausfiltern. Die Filter sollen in der Lage sein, alle gefilterten Dateien mit ihrem
	vollständigen Pfadnamen auszugeben! Bei der Filterung von Verweisen muss zusätzlich auch der
	Name des Elementes auf das verwiesen wird ausgegeben werden
*/

class FilterFiles :	public IVisitor {
public:
	void Visit(File& type) override;
	void Visit(Folder& type) override;
	void Visit(Referral& type) override;

	void SetMinSize(int minSize);
	void SetMaxSize(int maxSize);

private:
	Type* m_root = nullptr;
	int m_minSize = 1;
	int m_maxSize = 5;
	std::list<std::shared_ptr<Type>> m_filter;

	void FindFirstElement(Type& const type);
	std::string GetPath(Type& const type);
	void FilterBySize(Type& const type);
	void FilterByReferral(Type& const type);
	void Print(Type& const type);
};

#endif //!FILTERFILES_H

