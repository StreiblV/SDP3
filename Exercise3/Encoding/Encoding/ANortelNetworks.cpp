#include "ANortelNetworks.h"

ANortelNetworks::ANortelNetworks() {
	m_caesar = new Caesar;
	m_rsa = new RSA;
}

void ANortelNetworks::Encipher(TEncoding enc, std::string const& fileName)
{
	if (enc == TEncoding::eCaesar) {
		m_caesar->Encrypt(fileName);
	}
	else {
		m_rsa->Encrypt(fileName);
	}
}

void ANortelNetworks::Decipher(TEncoding enc, std::string const& fileName)
{
	if (enc == TEncoding::eCaesar) {
		m_caesar->Decrypt(fileName);
	}
	else {
		m_rsa->Decrypt(fileName);
	}
}
