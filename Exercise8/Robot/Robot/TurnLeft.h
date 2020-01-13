/* ______________________________________________________________________
| Workfile : TurnLeft.h
| Description : [ HEADER ]
| Name : Daniel Weyrer		PKZ : S1820306044
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#ifndef TURNLEFT_H
#define TURNLEFT_H

#include "ICommand.h"
#include "Robot.h"

class TurnLeft : public ICommand {
public:
	TurnLeft(std::shared_ptr<Robot> robot);

	virtual void Execute() override;
	virtual void Unexecute() override;
};

#endif // !TURNLEFT_H

