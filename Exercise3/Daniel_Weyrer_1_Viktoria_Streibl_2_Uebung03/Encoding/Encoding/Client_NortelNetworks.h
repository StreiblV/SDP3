/* ______________________________________________________________________
| Workfile : Client_NortelNetworks.h
| Description : [HEADER] Client uses the Interface INortelNetworks
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
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
	//Constructor
	Client_NortelNetworks(INortelNetworks& nortelNetworks);

	//calls the encryption by encoding type
	void Encipher(TEncoding type, std::string const& fileName);
	//calls the decryption by encoding type
	void Decipher(TEncoding type, std::string const& fileName);

private:
	INortelNetworks* m_nortelNetworks;
};
#endif //CLIENT_NORTEL_NETWORKS_H