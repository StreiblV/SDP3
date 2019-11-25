/* ______________________________________________________________________
| Workfile : SymbolParser.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
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
	//Konstruktor
	SymbolParser() = default;
	//Dekonstruktor
	~SymbolParser() = default;

	//add a type to the list
	void AddType(std::string const& name);

	//add a new variable to the list
	void AddVariable(std::string const& name, std::string const& type);

	//set the current programming language
	void SetFactory(SymbolFactory* fact);
private:
	SymbolFactory* m_fact = nullptr;
};

#endif // !SYMBOLPARSER_H