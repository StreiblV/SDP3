/* ______________________________________________________________________
| Workfile : Client.h
| Description : [ HEADER ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef CLIENT_H
#define CLIENT_H

#include "vld.h"

#include "Control.h"
#include "Forward.h"
#include "TurnLeft.h"
#include "TurnRight.h"
#include "MacroMovement.h"


#include "Robot.h"
#include "Wheelbot.h"
#include "Hexapod.h"

#include <iostream>
#include <memory>



class Client : public Object {
public:
	void Test();
};

#endif // !CLIENT_H

