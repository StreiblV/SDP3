/* ______________________________________________________________________
| Workfile : Encryptor.h
| Description : [ HEADER ] Base Class for encryptors
| Name : Daniel Weyrer									PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H
#include <fstream>
#include <iostream>
#include <string>
#include "Object.h"

class Encryptor : public Object {
public:
	virtual void Encrypt(std::string const& fileName) = 0;
	virtual void Decrypt(std::string const& fileName) = 0;

private:
	void GenFile(std::string const& newFileName, std::string const& content);
};

#endif // ENCRYPTOR_H