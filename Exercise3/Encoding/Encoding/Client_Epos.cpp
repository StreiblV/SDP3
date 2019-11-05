#include "Client_Epos.h"

Client_Epos::Client_Epos(IEpos& epos)
{
	m_epos = &epos;
}

void Client_Epos::EncryptRSA(std::string const& fileName)
{
	m_epos->EncryptRSA(fileName);
}

void Client_Epos::DecryptRSA(std::string const& fileName)
{
	m_epos->DecryptRSA(fileName);
}
