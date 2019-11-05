/* ______________________________________________________________________
| Workfile : Encryptor.cpp
| Description : [ SOURCE] Base Class for encryptors
| Name : Daniel Weyrer									PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Encryptor.h"

void Encryptor::GenFile(std::string const& newFileName, std::string const& content) {
	std::ofstream tmp;
	tmp.open(newFileName, std::ofstream::out);
	tmp << content;
	tmp.close();	
}
