/* ______________________________________________________________________
| Workfile : AEpos.h
| Description : [HEADER] Implements the INortelNetwors interface and
				handles which encryption/decryption should be used
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef ANORTEL_NETWORKS_H
#define ANORTEL_NETWORKS_H

#include "INortelNetworks.h"
#include "RSA.h"
#include "Caesar.h"

class ANortelNetworks : public INortelNetworks
{
public:
	//Constructor
	ANortelNetworks();
	//Default deconstructor
	~ANortelNetworks() = default;

	//encrypt the file based on the encoding type
	void Encipher(TEncoding enc, std::string const& fileName) override;
	//decrypt the file based on the encoding type
	void Decipher(TEncoding enc, std::string const& fileName) override;

private:
	RSA* m_rsa;
	Caesar* m_caesar;
};

#endif //ANORTEL_NETWORKS_H