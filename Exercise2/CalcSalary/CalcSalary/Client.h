/* ______________________________________________________________________
| Workfile : Client .h
| Description : [ HEADER ] Class for the Client to act with an Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#ifndef CLIENT_H
#define CLIENT_H

#include "ICompany.h"

class Client : public Object {

public:
	Client(ICompany* const company);
	~Client() = default;

	//tests if the company name is correct
	bool TestCompanyName(std::string expectedName) const;
	//tests if the company location is correct
	bool TestCompanyLocation(std::string expectedLocation) const;
	//tests if the employee which is search by his nickname is correct
	bool TestFindEmployeeByNickname(std::string nickname) const;
	//counts all employees and check if it is correct
	bool TestCountEmployees(int expectedResult) const;
	//counts all employees of one type and check it
	bool TestCountEmployeesByType(wBase type, int expectedResult) const;
	//count all procuded pieces and check them
	bool TestCountTotalProducesPieces(int expectedResult) const;
	//count all sold pieces and check them
	bool TestCountTotalSoldPieces(int expectedResult) const;
	//count how many employees are older than a specific year and check it
	bool TestCountEmployeesOlderThan(int year, int expectedResult) const;
	//tests if the salary of an employee is correct
	bool TestGetSalaryOfEmployee(std::string nickname, double expectedResult) const; 
	//tests if the oldest employee is correct
	bool TestGetOldestEmployee(std::string expectedNickname) const;
	//let print all data of company and employees
	bool TestPrintAll() const;

private:
	ICompany* m_company;

	void ErrorMsg(std::string msg) const;
};
#endif //CLIENT_H