/* ______________________________________________________________________
| Workfile : RSA.h
| Description : [ HEADER ] Derived Class to encrypt via RSA technique
| Name : Viktoria Streibl							PKZ : S1820306044
| Date : 05.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef RSA_H
#define RSA_H
#include "Encryptor.h"

class RSA : public Encryptor
{
	// Inherited via Encryptor
	virtual void Encrypt(std::string const& fileName) override;
	virtual void Decrypt(std::string const& fileName) override;
};

#endif //RSA_H