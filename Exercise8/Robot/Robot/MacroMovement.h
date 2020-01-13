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

#include "Control.h"
#include "ICommand.h"
#include "Robot.h"

class MacroMovement : public ICommand {
public:
	MacroMovement(std::shared_ptr<Robot> robot, Control::TcmdList const& movement) : ICommand{ robot }, m_movement{ movement }{}
	virtual void Execute() override;
	virtual void Unexecute() override;

private:
	Control::TcmdList m_movement;
	Control::TcmdList m_undoMovement;
};

#endif // !MACROMOVEMENT_H
