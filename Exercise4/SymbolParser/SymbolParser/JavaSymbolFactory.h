/* ______________________________________________________________________
| Workfile : JavaSymbolFactory.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef JAVASYMBOLFACTORY_H
#define JAVASYMBOLFACTORY_H

#include "SymbolFactory.h"

#include <iostream>
#include <fstream>

class JavaSymbolFactory : public SymbolFactory
{
public:
	static JavaSymbolFactory& GetInstance() {
		if (mInstance == nullptr) mInstance = std::unique_ptr<JavaSymbolFactory>(new JavaSymbolFactory);
		return *mInstance;
	}

	//free singleton before end of program
	static void Delete() { mInstance.reset(); }

	//write all types and variables into the files
	virtual void WriteIntoFile() override;

	//read all types and variables from the files
	virtual void ReadFromFile() override;

private:
	//hide default ctor
	JavaSymbolFactory() = default;
	JavaSymbolFactory(JavaSymbolFactory const&) = delete;
	JavaSymbolFactory& operator= (JavaSymbolFactory const&) = delete;
	static std::unique_ptr<JavaSymbolFactory> mInstance;

	//JavaTypes.sym und JavaVars.sym
	std::string typeFilename = "JavaTypes.sym";
	std::string varFilename = "JavaVars.sym";
};

#endif // !JAVASYMBOLFACTORY_H