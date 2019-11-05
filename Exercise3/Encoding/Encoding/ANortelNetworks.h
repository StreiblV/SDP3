/* ______________________________________________________________________
| Workfile : ICompany .h
| Description : [ Interface ] Interface between Client and Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef ANORTEL_NETWORKS_H
#define ANORTEL_NETWORKS_H

#include "INortelNetworks.h"

class AEpos : public INortelNetworks
{
public:
	void Encipher(TEncoding enc, std::string const& fileName) override;
	void Decipher(TEncoding enc, std::string const& fileName) override;
};

#endif //ANORTEL_NETWORKS_H