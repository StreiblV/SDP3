/* ______________________________________________________________________
| Workfile : ICompany .h
| Description : [ Interface ] Interface between Client and Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef CLIENT_EPOS_H
#define CLIENT_EPOS_H

#include "Object.h"
#include "IEpos.h"

class Client_Epos : public Object
{
public:
	Client_Epos(IEpos& epos);

	void EncryptRSA(std::string const& fileName);
	void DecryptRSA(std::string const& fileName);

private:
	IEpos* m_epos;
};

#endif //CLIENT_EPOS_H