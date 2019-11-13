/* ______________________________________________________________________
| Workfile : Client_NortelNetworks.cpp
| Description : [SOURCE] Client uses the Interface INortelNetworks
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
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
