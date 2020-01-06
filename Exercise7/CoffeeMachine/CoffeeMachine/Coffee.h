/* ______________________________________________________________________
| Workfile : Coffee.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef COFFEE_H
#define COFFEE_H

#include "Coffeemachine.h"

class Coffee : public Coffeemachine {
	virtual std::string GetDescription() = 0;
	virtual double GetCost() = 0;
};


#endif //!COFFEE_H
