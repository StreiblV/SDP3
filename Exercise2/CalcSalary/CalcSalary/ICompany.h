#pragma once
#include <stdio.h>
#include <string>
#include <list>

#include "Employee.h"

class ICompany {
public:
	virtual std::string GetCompanyName() = 0;
	virtual std::string GetCompanyLocation() = 0;
	virtual void GetEmployee(std::string nickname) = 0;
	virtual void GetEmployee(wBase type) = 0;
	virtual int GetSoldPieces() = 0;
	virtual int GetProdPieces() = 0;
	virtual int CountEmployees() = 0;
	virtual int CountEmployess(Employee::TDate birthday) = 0;
	virtual void Print() = 0;
};