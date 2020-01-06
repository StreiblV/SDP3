/* ______________________________________________________________________
| Workfile : Decaffeinated.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef DECAFFEINATED_H
#define DECAFFEINATED_H

#include <string>

#include "Pricelist.h"
#include "Coffeemachine.h"

class Decaffeinated : public Coffeemachine {

	std::string GetDescription() override;
	double GetCost() override;
};

#endif //!DECAFFEINATED_H

