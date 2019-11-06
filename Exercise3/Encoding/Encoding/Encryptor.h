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
#include <iterator>

#include "Object.h"

class Encryptor : public Object {
public:
	Encryptor() = default;
	virtual ~Encryptor() = default;
	virtual void Encrypt(std::string const& fileName) = 0;
	virtual void Decrypt(std::string const& fileName) = 0;

protected:
	virtual void GenFile(std::string const& FileName, std::string const& content);
	std::string ReadFile(std::string const& fileName);
};

#endif // ENCRYPTOR_H