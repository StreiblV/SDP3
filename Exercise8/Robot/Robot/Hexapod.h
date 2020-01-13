/* ______________________________________________________________________
| Workfile : Hexapod.h
| Description : [ HEADER ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef HEXAPOD_H
#define HEXAPOD_H


#include "Robot.h"
class Hexapod : public Robot {
public:
	//cTor
	Hexapod(std::string const& name) : Robot(name) {}

	//Prints all Information if valid ost is given
	virtual void Info(std::ostream& ost) override;
};

#endif//!HEXAPOD_H
