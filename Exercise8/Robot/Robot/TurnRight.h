/* ______________________________________________________________________
| Workfile : TurnRight.h
| Description : [ HEADER ]
| Name : Daniel Weyrer		PKZ : S1820306044
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef TURNRIGHT_H
#define TURNRIGHT_H

#include "ICommand.h"
#include "Robot.h"

class TurnRight : public ICommand {
	TurnRight(std::shared_ptr<Robot> robot) : ICommand{ robot } {}
	virtual void Execute() override;
	virtual void Unexecute() override;
};

#endif // !TURNRIGHT_H
