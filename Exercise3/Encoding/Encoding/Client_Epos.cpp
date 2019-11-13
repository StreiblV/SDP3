/* ______________________________________________________________________
| Workfile : Client_Epos.cpp
| Description : [SOURCE] Client uses the Interface IEpos
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
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
