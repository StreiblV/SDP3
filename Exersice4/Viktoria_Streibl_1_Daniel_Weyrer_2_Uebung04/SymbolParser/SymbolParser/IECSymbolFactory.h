/* ______________________________________________________________________
| Workfile : IECSymbolFactory.cpp
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef IECSYMBOLFACTORY_H
#define IECSYMBOLFACTORY_H

#include <iostream>
#include <fstream>

#include "SymbolFactory.h"

class IECSymbolFactory : public SymbolFactory
{
public:
	//create singleton instance
	static IECSymbolFactory& GetInstance() {
		if (mInstance == nullptr) mInstance = std::unique_ptr<IECSymbolFactory>(new IECSymbolFactory);
		return *mInstance;
	}
	//free singleton before end of program
	static void Delete() { 
		mInstance.reset(); 
		mInstance.get()->WriteIntoFile();
	}

	//write all types and variables into the file
	virtual void WriteIntoFile() override;

	//read all types and variables from the files
	virtual void ReadFromFile() override;

private:
	//hide default ctor
	IECSymbolFactory() = default;
	IECSymbolFactory(IECSymbolFactory const&) = delete;
	IECSymbolFactory& operator= (IECSymbolFactory const&) = delete;
	static std::unique_ptr<IECSymbolFactory> mInstance;

	//IECTypes.sym und IECVars.sym
	std::string typeFilename = "IECTypes.sym";
	std::string varFilename = "IECVars.sym";
};

#endif // !IECSYMBOLFACTORY_H