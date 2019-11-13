/* ______________________________________________________________________
| Workfile : AEpos.h
| Description : [HEADER] Implements the IEpos interface
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef AEPOS_H
#define AEPOS_H

#include "IEpos.h"
#include "RSA.h"

class AEpos : public IEpos
{
public:
	//Constructor
	AEpos();
	//Default deconstructor
	~AEpos() = default;

	//encrypt the file with RSA
	void EncryptRSA(std::string const& fileName) override;

	//decrypt the file with RSA
	void DecryptRSA(std::string const& fileName) override;

private:
	RSA* m_rsa;
};

#endif //AEPOS_H