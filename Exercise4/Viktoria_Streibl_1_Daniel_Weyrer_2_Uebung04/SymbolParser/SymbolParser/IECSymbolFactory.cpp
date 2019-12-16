/* ______________________________________________________________________
| Workfile : ICESymbolFactory.cpp
| Description : [ SOURCE ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "IECSymbolFactory.h"

using namespace std;

//init static member
std::unique_ptr<IECSymbolFactory> IECSymbolFactory::mInstance{ nullptr };

void IECSymbolFactory::WriteIntoFile() {
	ofstream outdataTyp;
	ofstream outdataVar;

	outdataTyp.open(typeFilename); // opens the file
	if (!outdataTyp) { // file couldn't be opened
		cerr << "Error: file for types could not be opened" << endl;
	}
	else {
		//write into file
		for (int i = 0; i < m_types.size(); ++i) {
			outdataTyp << "TYPE " << m_types.at(i) << endl;
		}
	}

	outdataVar.open(varFilename); // opens the file
	if (!outdataVar) { // file couldn't be opened
		cerr << "Error: file for variables could not be opened" << endl;
	}
	else {
		//write into file
		for (int i = 0; i < m_variables.size(); ++i) {
			outdataVar << "VAR " << m_variables.at(i).first << " : " << m_variables.at(i).second << ";" << endl;
		}
	}
	outdataTyp.close();
	outdataVar.close();
}

void IECSymbolFactory::ReadFromFile() {
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
			std::string type = tp.substr(tp.find(" ") + 1, tp.find(" :"));
			std::string var = tp.substr(tp.find(": ") + 1, tp.find(";"));
			AddVariable(var, type);
		}
	}

	outdataType.close();
	outdataVar.close();
}