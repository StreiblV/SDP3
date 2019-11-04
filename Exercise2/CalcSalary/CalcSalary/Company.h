#pragma once

#include <string>
#include <list>

#include "ICompany.h"
#include "Employee.h"

class Company : public ICompany
{

public:
	Company(std::string name, std::string location);

	std::string GetCompanyName() override;
	std::string GetCompanyLocation() override;
	Employee* GetEmployee(std::string nickname) override;
	//Employee* GetEmployee(Type type) override;
	int GetSoldPieces() override;
	int GetProdPieces() override;
	int CountEmployees() override;
	//int CountEmployess(Date birthday) override;
	void Print() override;

	void AddEmployee(Employee e);
	void DeleteEmployee(Employee e);

private:
	std::string m_name;
	std::string m_location;
	std::list<Employee> m_employees;
};

