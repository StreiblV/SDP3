/* ______________________________________________________________________
| Workfile : Espresso.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef ESPRESSO_H
#define ESPRESSO_H

#include <string>

#include "Pricelist.h"
#include "Coffeemachine.h"

class Espresso : public Coffeemachine {

	std::string GetDescription() override;
	double GetCost() override;
};

#endif //!ESPRESSO_H


