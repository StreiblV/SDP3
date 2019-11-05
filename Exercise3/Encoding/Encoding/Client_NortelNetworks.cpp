#include "Client_NortelNetworks.h"

Client_NortelNetworks::Client_NortelNetworks(INortelNetworks& nortelNetworks)
{
	m_nortelNetworks = &nortelNetworks;
}

void Client_NortelNetworks::Encipher(TEncoding type, std::string const& fileName)
{
	m_nortelNetworks->Encipher(type, fileName);
}

void Client_NortelNetworks::Decipher(TEncoding type, std::string const& fileName)
{
	m_nortelNetworks->Decipher(type, fileName);
}
