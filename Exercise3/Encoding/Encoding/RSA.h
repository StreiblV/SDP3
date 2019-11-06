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

static const size_t n_default = 187;
static const size_t e_default = 7;
static const size_t d_default = 23;

class RSA : public Encryptor {
public:
	RSA() : n{ n_default }, e{ e_default }, d{ d_default }{}
	virtual ~RSA() override = default;

	// Inherited via Encryptor
	virtual void Encrypt(std::string const& fileName) override;
	virtual void Decrypt(std::string const& fileName) override;
	virtual void GenFile(std::string const& newFileName, std::string const& content) override;
private:
	size_t n;
	size_t e;
	size_t d;

};

#endif //RSA_H