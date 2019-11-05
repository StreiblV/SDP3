	/* ______________________________________________________________________
| Workfile : Company .h
| Description : [ HEADER ] Class Company to store all data
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <list>

#include "ICompany.h"
#include "Employee.h"

typedef std::unique_ptr<Employee> EUptr;
typedef std::list<EUptr>::const_iterator EIter;

class Company : public ICompany
{

public:
	//create company with name and location
	Company(std::string const name, std::string const location);
	~Company() = default;

	//returns the name of the company
	std::string GetCompanyName() override;
	//returns the location of the company
	std::string GetCompanyLocation() override;
	//print a employee found by the nickname
	void GetEmployee(std::string const nickname) override;
	//print all employees of the type
	void GetEmployee(wBase type) override;
	//return total sold pieces last month
	int GetSoldPieces() override;
	//return total produced pieces last month
	int GetProdPieces() override;
	//return the salary of the employee
	double GetSalaryOfEmployee(std::string nickname) override;
	//returns the nickname of the oldest employee
	std::string GetOldestEmployee() override;
	//check for the employee with is the oldest member
	std::string GetEmployeeWithLongestTimeInCompany() override;
	//returns the number of employees in the company
	int CountEmployees() override;
	//returns the number of employees of a specific type in the company
	int CountEmployees(wBase type) override;
	//returns the number of employees older than a specific year
	int CountEmployeesOlderThan(int year) override;
	//print all data of the company and employees
	void Print() override;

	//add an employee
	void AddEmployee(EUptr e);
	//delete an employee
	void DeleteEmployee(EUptr e);

private:
	std::string m_name;
	std::string m_location;
	std::list<EUptr> m_employees;

	//find an employee by nickname
	EIter FindEmployee(std::string nickname);
};
#endif //COMPANY_H