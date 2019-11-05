/* ______________________________________________________________________
| Workfile : ICompany .h
| Description : [ Interface ] Interface between Client and Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef CLIENT_NORTEL_NETWORKS_H
#define CLIENT_NORTEL_NETWORKS_H

#include "Object.h"
#include "INortelNetworks.h"

class Client_NortelNetworks : public Object
{
public:
	Client_NortelNetworks(INortelNetworks& nortelNetworks);

	void Encipher(TEncoding type, std::string const& fileName);
	void Decipher(TEncoding type, std::string const& fileName);

private:
	INortelNetworks* m_nortelNetworks;
};

#endif //CLIENT_NORTEL_NETWORKS_H