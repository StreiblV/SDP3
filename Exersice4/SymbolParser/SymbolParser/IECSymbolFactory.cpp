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

	m_types.clear();
	m_variables.clear();
}