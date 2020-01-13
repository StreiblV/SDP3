/* ______________________________________________________________________
| Workfile : TurnLeft.h
| Description : [ HEADER ]
| Name : Daniel Weyrer		PKZ : S1820306044
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef ICOMMAND_H
#define ICOMMAND_H

#include "IRobot.h"
#include "Robot.h"

#include<memory>


class ICommand {
public:
	ICommand(std::shared_ptr<Robot> robot);
	virtual void Execute() = 0;
	virtual void Unexecute() = 0;

	using SPtr = std::shared_ptr<ICommand>;

private:
	std::shared_ptr<Robot> m_robot;
};

#endif // !ICOMMAND_H