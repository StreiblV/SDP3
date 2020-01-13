/* ______________________________________________________________________
| Workfile : Forward.h
| Description : [ HEADER ]
| Name : Daniel Weyrer		PKZ : S1820306044
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef FORWARD_H
#define FORWARD_H


#include "ICommand.h"
#include "Robot.h"

class Forward :	public ICommand {
public:
	Forward(std::shared_ptr<Robot> robot, int const distance) : ICommand{ robot }, m_distance{ distance } {}
	virtual void Execute() override;
	virtual void Unexecute() override;

private:
	int m_distance;
};

#endif // !FORWARD_H

