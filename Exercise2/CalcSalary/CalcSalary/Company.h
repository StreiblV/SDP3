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
	Company(std::string const name, std::string const location);
	~Company() = default;

	std::string GetCompanyName() override;
	std::string GetCompanyLocation() override;
	void GetEmployee(std::string const nickname) override;
	void GetEmployee(wBase type) override;
	int GetSoldPieces() override;
	int GetProdPieces() override;
	double GetSalaryOfEmployee(std::string nickname) override;
	std::string GetOldestEmployee() override;
	int CountEmployees() override;
	int CountEmployees(wBase type) override;
	int CountEmployeesOlderThan(int year) override;
	void Print() override;

	void AddEmployee(EUptr e);
	void DeleteEmployee(EUptr e);

private:
	std::string m_name;
	std::string m_location;
	std::list<EUptr> m_employees;

	EIter FindEmployee(std::string nickname);
};
#endif //COMPANY_H