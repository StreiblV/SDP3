/* ______________________________________________________________________
| Workfile : Wheelpod.h
| Description : [ HEADER ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef WHEELBOT_H
#define WHEELBOT_H

#include "Robot.h"

#include <ostream>

class Wheelbot : public Robot {
public:
	//cTor
	Wheelbot(std::string const& name) : Robot(name) {}
	
	//Prints all Information if valid ost is given
	virtual void Info(std::ostream& ost) override;
};

#endif//!WHEELBOT_H

