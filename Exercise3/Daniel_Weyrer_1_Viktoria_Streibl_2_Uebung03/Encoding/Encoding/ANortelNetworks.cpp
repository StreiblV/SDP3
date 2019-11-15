/* ______________________________________________________________________
| Workfile : AEpos.h
| Description : [SOURCE] Implements the INortelNetwors interface and
				handles which encryption/decryption should be used
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "ANortelNetworks.h"

ANortelNetworks::ANortelNetworks() {
	m_caesar = new Caesar;
	m_rsa = new RSA;
}

void ANortelNetworks::Encipher(TEncoding enc, std::string const& fileName)
{
	//check if the encoding type is caesar
	if (enc == TEncoding::eCaesar) {
		m_caesar->Encrypt(fileName);
	}
	else {
		m_rsa->Encrypt(fileName);
	}
}

void ANortelNetworks::Decipher(TEncoding enc, std::string const& fileName)
{
	//check if the encoding type is caesar
	if (enc == TEncoding::eCaesar) {
		m_caesar->Decrypt(fileName);
	}
	else {
		m_rsa->Decrypt(fileName);
	}
}
