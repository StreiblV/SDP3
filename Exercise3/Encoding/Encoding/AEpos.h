/* ______________________________________________________________________
| Workfile : ICompany .h
| Description : [ Interface ] Interface between Client and Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef AEPOS_H
#define AEPOS_H

#include "IEpos.h"

class AEpos : public IEpos
{
public:
	void EncryptRSA(std::string const& fileName) override;
	void DecryptRSA(std::string const& fileName) override;

};

#endif //AEPOS_H