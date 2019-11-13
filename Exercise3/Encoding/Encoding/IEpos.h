/* ______________________________________________________________________
| Workfile : IEpos.h
| Description : [ Interface ] Interface between Client and RSA and Caesar
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 08.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef IEPOS_H
#define IEPOS_H

#include <string>
#include "Object.h"

class IEpos : public Object {
public:
	//Default Constructor
	IEpos() = default;
	//Default Destructor
	~IEpos() = default;

	//calls the encrpytion method for RSA
	virtual void EncryptRSA(std::string const& fileName) = 0;
	//calls the decrpytion method for RSA
	virtual void DecryptRSA(std::string const& fileName) = 0;
};

#endif //IEPOS_H