/* ______________________________________________________________________
| Workfile : ICompany .h
| Description : [ Interface ] Interface between Client and Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef ICOMPANY_H
#define ICOMPANY_H

#include <stdio.h>
#include <string>
#include <list>

#include "Object.h"
#include "Employee.h"

class ICompany : public Object {
public:
	ICompany() = default;
	~ICompany() = default;

	//returns the name of the company
	virtual std::string GetCompanyName() = 0;
	//returns the location of the company
	virtual std::string GetCompanyLocation() = 0;
	//print a employee found by the nickname
	virtual void GetEmployee(std::string nickname) = 0;
	//print all employees of the type
	virtual void GetEmployee(wBase type) = 0;
	//return total sold pieces last month
	virtual int GetSoldPieces() = 0;
	//return total produced pieces last month
	virtual int GetProdPieces() = 0;
	//return the salary of the employee
	virtual double GetSalaryOfEmployee(std::string nickname) = 0;
	//returns the nickname of the oldest employee
	virtual std::string GetOldestEmployee() = 0;
	//returns the number of employees in the company
	virtual int CountEmployees() = 0;
	//returns the number of employees of a specific type in the company
	virtual int CountEmployees(wBase type) = 0;
	//returns the number of employees older than a specific year
	virtual int CountEmployeesOlderThan(int year) = 0;
	//print all data of the company and employees
	virtual void Print() = 0;
};
#endif //ICOMPANY_H