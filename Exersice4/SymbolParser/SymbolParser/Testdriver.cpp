/* ______________________________________________________________________
| Workfile : Testdriver.cpp
| Description : [ SOURCE ] Class for testing all functions
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "SymbolParser.h"
#include "JavaSymbolFactory.h"
#include "IECSymbolFactory.h"

int main() {
	SymbolParser parser;

	std::cout << "Test 1..." << std::endl;
	JavaSymbolFactory& fact = JavaSymbolFactory::GetInstance();
	parser.SetFactory(&fact);
	parser.AddType("Button");
	parser.AddType("Hugo");
	parser.AddType("Window");
	parser.AddVariable("mButton", "Button");
	parser.AddVariable("mWin", "Window");

	std::cout << "Test 2..." << std::endl;
	parser.SetFactory(&IECSymbolFactory::GetInstance());
	parser.AddType("SpeedController");
	parser.AddType("Hugo");
	parser.AddType("Nero");
	parser.AddVariable("mCont", "SpeedController");
	parser.AddVariable("mHu", "Hugo");

	std::cout << "Test 3..." << std::endl;
	parser.SetFactory(&JavaSymbolFactory::GetInstance());
	parser.AddVariable("b", "Button");

	std::cout << "Test 4..." << std::endl;
	parser.SetFactory(&IECSymbolFactory::GetInstance());
	parser.AddType("Hugo");
	parser.AddVariable("mCont", "Hugo");

	return 0;
}