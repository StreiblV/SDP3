/* ______________________________________________________________________
| Workfile : SymbolParser.h
| Description : [ HEADER ]
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 24.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef SYMBOLFACTORY_H
#define SYMBOLFACTORY_H

#include <stdio.h>
#include <iostream>
#include <exception>
#include <memory>
#include <string>
#include <vector>

typedef std::vector<std::string> Types;
typedef std::pair<std::string, std::string> Variable;
typedef std::vector<Variable> Variables;

//template singleton base class
class SymbolFactory {
	
public:
	SymbolFactory() = default;
	~SymbolFactory() = default;
	//create new type
	void AddType(std::string const& name);

	//create new variable
	void AddVariable(std::string const& name, std::string const& type);

	//write all types and variables into the file
	virtual void WriteIntoFile() = 0;

	//read from the file
	virtual void ReadFromFile() = 0;

protected:	
	//vector types
	Types m_types;
	//vector variables(pair)
	Variables m_variables;
};

//
//Exceptions
//
struct TypeAlreadyDefinedException : public std::exception
{
	const std::string what(std::string typeName) const throw ()
	{
		return "Type " + typeName + " is already defined.";
	}
};

struct VariableAlreadyDefinedException : public std::exception
{
	const std::string what(std::string varName) const throw ()
	{
		return "Variable " + varName + " is already defined.";
	}
};
struct TypeNotDefinedException : public std::exception
{
	const std::string what(std::string typeName) const throw ()
	{
		return "Type " + typeName + " is not defined.";
	}
};


#endif // !SYMBOLFACTORY_H