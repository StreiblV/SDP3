/* ______________________________________________________________________
| Workfile : Control.h
| Description : [ HEADER ]
| Name : Daniel Weyrer		PKZ : S1820306044
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef OBJECT_H
#define OBJECT_H

#include "Object.h"
#include "ICommand.h"
#include "vector"
#include <memory>

class Control : public Object {
public:
	typedef std::shared_ptr<ICommand> TcmdPtr;
	typedef std::vector<TcmdPtr> TcmdList;

	//Adds command to Commandlist
	void AddCommand(TcmdPtr cmd);
	
	//Starts execution of all commands in Commandlist
	void Start();

	//executes Unexecute() of "count"-Items in Undo-List
	void Undo(size_t const count);
	
	//Removes all added Commands
	void Reset();

private:
	TcmdList m_commands;
	TcmdList m_undoList;
};

#endif // !OBJECT_H

