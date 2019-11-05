#include "AEpos.h"

void AEpos::EncryptRSA(std::string const& fileName)
{
	m_rsa->Encrypt(fileName);
}

void AEpos::DecryptRSA(std::string const& fileName)
{
	m_rsa->Decrypt(fileName);
}
