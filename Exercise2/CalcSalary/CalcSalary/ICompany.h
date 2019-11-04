#pragma once
#include <stdio.h>
#include <string>

#include "Employee.h"

class ICompany {
public:
	virtual std::string GetCompanyName() = 0;
	virtual std::string GetCompanyLocation() = 0;
	virtual Employee* GetEmployee(std::string nickname) = 0;
	//virtual Employee* GetEmployee(Type type) = 0;
	virtual int GetSoldPieces() = 0;
	virtual int GetProdPieces() = 0;
	virtual int CountEmployees() = 0;
	//virtual int CountEmployess(Date birthday) = 0;
	virtual void Print() = 0;
};