/* ______________________________________________________________________
| Workfile : Client_Epos.h
| Description : [HEADER] Client uses the Interface IEpos
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
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
	//Constructor
	Client_Epos(IEpos& epos);

	//calls the encryption logic
	void EncryptRSA(std::string const& fileName);

	//calls the decryption logic
	void DecryptRSA(std::string const& fileName);

private:
	IEpos* m_epos;
};

#endif //CLIENT_EPOS_H