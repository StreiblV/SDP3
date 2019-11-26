/* ______________________________________________________________________
| Workfile : JavaSymbolFactory.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "JavaSymbolFactory.h"

std::unique_ptr<JavaSymbolFactory> JavaSymbolFactory::mInstance{ nullptr };
using namespace std;

void JavaSymbolFactory::WriteIntoFile() {
	ofstream outdata;

	outdata.open(typeFilename); // opens the file
	if (!outdata) { // file couldn't be opened
		cerr << "Error: file for types could not be opened" << endl;
	}
	else {
		for (int i = 0; i < m_types.size(); ++i) {
			outdata << "class " << m_types.at(i) << endl;
		}
	}
	outdata.close();

	outdata.open(varFilename); // opens the file
	if (!outdata) { // file couldn't be opened
		cerr << "Error: file for variables could not be opened" << endl;
	}
	else {
		for (int i = 0; i < m_variables.size(); ++i) {
			outdata << m_variables.at(i).second << " " << m_variables.at(i).first << ";" << endl;
		}
	}
	outdata.close();
}

void JavaSymbolFactory::ReadFromFile() {
	std::ifstream outdataType;
	std::ifstream outdataVar;

	outdataType.open(typeFilename, std::ios::in); //open a file to perform read operation using file object
	if (outdataType.is_open()) {   //checking whether the file is open
		std::string tp;
		while (std::getline(outdataType, tp)) { //read data from file object and put it into string.
			std::string type = tp.substr(tp.find(" ") + 1, tp.length());
			AddType(type);

		}
	}

	outdataVar.open(varFilename, std::ios::in); //open a file to perform read operation using file object
	if (outdataVar.is_open()) {   //checking whether the file is open
		std::string tp;
		while (std::getline(outdataVar, tp)) { //read data from file object and put it into string.
			std::string type = tp.substr(0, tp.find(" "));
			std::string var = tp.substr(tp.find(" ") + 1, tp.find(";"));
			AddVariable(var, type);
		}
	}

	outdataType.close();
	outdataVar.close();
}