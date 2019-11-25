/* ______________________________________________________________________
| Workfile : SymbolParser.cpp
| Description : [ SOURCE ] 
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "SymbolParser.h"

SymbolParser::~SymbolParser() {
	m_fact->WriteIntoFile();
	IECSymbolFactory::Delete();
	JavaSymbolFactory::Delete();
}

void SymbolParser::AddType(std::string const& name) {
	m_fact->AddType(name);
}

void SymbolParser::AddVariable(std::string const& name, std::string const& type) {
	m_fact->AddVariable(name, type);
}

void SymbolParser::SetFactory(SymbolFactory* fact) {
	if (m_fact != nullptr) {
		m_fact->WriteIntoFile();
	}
	m_fact = fact;
}