/* ______________________________________________________________________
| Workfile : INortelNetworks.h
| Description : [ Interface ] Interface between Client and RSA and Caesar
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef INORTEL_NETWORKS_H
#define INORTEL_NETWORKS_H

#include <string>
#include "Object.h"

//enum for the encoding types
enum class TEncoding {
	eRSA,
	eCaesar
};

class INortelNetworks : public Object {
public:
	//Default Constructor
	INortelNetworks() = default;
	//Default Destructor
	~INortelNetworks() = default;

	//calls the correct encryption method by type
	virtual void Encipher(TEncoding enc, std::string const& fileName) = 0;
	//calls the correct decryption method by type
	virtual void Decipher(TEncoding enc, std::string const& fileName) = 0;
};

#endif //INORTEL_NETWORKS_H