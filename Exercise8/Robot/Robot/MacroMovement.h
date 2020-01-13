/* ______________________________________________________________________
| Workfile : Forward.h
| Description : [ HEADER ]
| Name : Daniel Weyrer		PKZ : S1820306044
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef MACROMOVEMENT_H
#define MACROMOVEMENT_H


#include "ICommand.h"
#include "Robot.h"

class MacroMovement : public ICommand {
	MacroMovement(std::shared_ptr<Robot> robot);
	virtual void Execute() override;
	virtual void Unexecute() override;
};

#endif // !MACROMOVEMENT_H
