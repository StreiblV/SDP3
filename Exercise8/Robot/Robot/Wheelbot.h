/* ______________________________________________________________________
| Workfile : Wheelpod.h
| Description : [ HEADER ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef ROBOT_H
#define ROBOT_H

#include "Robot.h"


class Wheelbot : public Robot {
public:
	virtual void Info(std::ostream& ost) override;
};

#endif//!ROBOT_H

