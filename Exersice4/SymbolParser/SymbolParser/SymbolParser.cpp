/* ______________________________________________________________________
| Workfile : SymbolParser.cpp
| Description : [ SOURCE ] 
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "SymbolParser.h"

<<<<<<< HEAD
SymbolParser::~SymbolParser() {
	m_fact->WriteIntoFile();
	IECSymbolFactory::Delete();
	JavaSymbolFactory::Delete();
}

=======
//calls the addType function of the language
>>>>>>> 4-viktoria
void SymbolParser::AddType(std::string const& name) {
	m_fact->AddType(name);
}

//calls the addVariable function of the language
void SymbolParser::AddVariable(std::string const& name, std::string const& type) {
	m_fact->AddVariable(name, type);
}

//set current factory
void SymbolParser::SetFactory(SymbolFactory* fact) {
	if (m_fact != nullptr) {
		m_fact->WriteIntoFile();
	}
	m_fact = fact;
}