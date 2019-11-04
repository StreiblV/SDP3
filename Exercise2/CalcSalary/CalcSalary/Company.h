#pragma once

#include <string>
#include <list>

#include "ICompany.h"
#include "Employee.h"

typedef std::unique_ptr<Employee> EUptr;
typedef std::list<EUptr>::const_iterator EIter;

class Company : public ICompany
{

public:
	Company(std::string const name, std::string const location);

	std::string GetCompanyName() override;
	std::string GetCompanyLocation() override;
	void GetEmployee(std::string const nickname) override;
	void GetEmployee(wBase type) override;
	int GetSoldPieces() override;
	int GetProdPieces() override;
	int CountEmployees() override;
	int CountEmployess(Employee::TDate birthday) override;
	void Print() override;

	void AddEmployee(EUptr e);
	void DeleteEmployee(EUptr e);

private:
	std::string m_name;
	std::string m_location;
	std::list<EUptr> m_employees;

	EIter FindEmployee(std::string nickname);
};

