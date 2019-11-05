#include "ANortelNetworks.h"

void AEpos::Encipher(TEncoding enc, std::string const& fileName)
{
	if (enc == TEncoding::eCaesar) {
		m_ceasar->Encrypt(fileName);
	}
	else {
		m_rsa->Encrypt(fileName);
	}
}

void AEpos::Decipher(TEncoding enc, std::string const& fileName)
{
	if (enc == TEncoding::eCaesar) {
		m_ceasar->Decrypt(fileName);
	}
	else {
		m_rsa->Decrypt(fileName);
	}
}
