/* ______________________________________________________________________
| Workfile : ICompany .h
| Description : [ Interface ] Interface between Client and Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef IEPOS_H
#define IEPOS_H

#include <string>
#include "Object.h"

class IEpos : public Object {
public:
	virtual void EncryptRSA(std::string const& fileName) = 0;
	virtual void DecryptRSA(std::string const& fileName) = 0;
};

#endif //IEPOS_H