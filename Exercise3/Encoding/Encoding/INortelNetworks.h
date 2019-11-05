/* ______________________________________________________________________
| Workfile : ICompany .h
| Description : [ Interface ] Interface between Client and Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef INORTEL_NETWORKS_H
#define INORTEL_NETWORKS_H

#include <string>
#include "Object.h"

enum class TEncoding {
	eRSA,
	eCaesar
};

class INortelNetworks : public Object {
public:
	virtual void Encipher(TEncoding enc, std::string const& fileName) = 0;
	virtual void Decipher(TEncoding enc, std::string const& fileName) = 0;
};

#endif //INORTEL_NETWORKS_H