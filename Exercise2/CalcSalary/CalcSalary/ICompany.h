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
	virtual std::string GetCompanyName() = 0;
	virtual std::string GetCompanyLocation() = 0;
	virtual void GetEmployee(std::string nickname) = 0;
	virtual void GetEmployee(wBase type) = 0;
	virtual int GetSoldPieces() = 0;
	virtual int GetProdPieces() = 0;
	virtual double GetSalaryOfEmployee(std::string nickname) = 0;
	virtual std::string GetOldestEmployee() = 0;
	virtual int CountEmployees() = 0;
	virtual int CountEmployees(wBase type) = 0;
	virtual int CountEmployeesOlderThan(int year) = 0;
	virtual void Print() = 0;
};
#endif //ICOMPANY_H