/* ______________________________________________________________________
| Workfile : Coffeemachine.h
| Description : [ HEADER ]
| Name : Daniel Weyrer			PKZ : S1820306044
| Date : 06.01.20
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef COFFEEMACHINE_H
#define COFFEEMACHINE_H

#include "Object.h"
#include <string>

class Coffeemachine : public Object{
public:
	void GetDisplay();
	virtual std::string GetDescription() = 0;
	virtual double GetCost() = 0;

private:
	std::string m_name;

};


#endif //!COFFEEMACHINE_H
