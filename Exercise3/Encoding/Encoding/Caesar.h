/* ______________________________________________________________________
| Workfile : Caesar.h
| Description : [ SOURCE ] Derived Class to encrypt via Caeser-procedure
| Name : Daniel Weyrer								PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef CAESAR_H
#define CAESAR_H

#include <algorithm>

#include "Encryptor.h"
static const unsigned int encryptionKey = 98;

class Caesar : public Encryptor {
public:
	Caesar() : key{ encryptionKey } {}
	virtual ~Caesar() override = default;

	// Inherited via Encryptor
	virtual void Encrypt(std::string const& fileName) override;
	virtual void Decrypt(std::string const& fileName) override;


private:
	unsigned int key;
	//helper methods
	
};

#endif //CAESAR_H