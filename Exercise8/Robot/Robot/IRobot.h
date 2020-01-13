/* ______________________________________________________________________
| Workfile : IRobot.h
| Description : [ HEADER ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef IROBOT_H
#define IROBOT_H

#include <iostream>

class IRobot {
public:
	// Prints current Robotinformation
	virtual void Info(std::ostream& ost) = 0;
	virtual ~IRobot();
};

#endif // !IROBOT_H

