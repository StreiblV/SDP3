/* ______________________________________________________________________
| Workfile : SymbolParser.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef SYMBOLPARSER_H
#define SYMBOLPARSER_H

#include <string>

#include "Object.h"
#include "SymbolFactory.h"
#include "JavaSymbolFactory.h"
#include "IECSymbolFactory.h"

class SymbolParser : public Object
{
public:
	SymbolParser() = default;
	~SymbolParser() = default;
	void AddType(std::string const& name);
	void AddVariable(std::string const& name, std::string const& type);

	void SetFactory(SymbolFactory* fact);
private:
	SymbolFactory* m_fact = nullptr;
};

#endif // !SYMBOLPARSER_H