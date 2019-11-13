/* ______________________________________________________________________
| Workfile : AEpos.cpp
| Description : [SOURCE] Implements the IEpos interface
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "AEpos.h"

AEpos::AEpos() {
	m_rsa = new RSA;
}

void AEpos::EncryptRSA(std::string const& fileName)
{
	m_rsa->Encrypt(fileName);
}

void AEpos::DecryptRSA(std::string const& fileName)
{
	m_rsa->Decrypt(fileName);
}
