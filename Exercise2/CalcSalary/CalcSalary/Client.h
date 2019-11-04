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

	bool TestCompanyName(std::string expectedName) const;
	bool TestCompanyLocation(std::string expectedLocation) const;
	bool TestFindEmployeeByNickname(std::string nickname) const;
	bool TestCountEmployees(int expectedResult) const;
	bool TestCountEmployeesByType(wBase type, int expectedResult) const;
	bool TestCountTotalProducesPieces(int expectedResult) const;
	bool TestCountTotalSoldPieces(int expectedResult) const;
	bool TestCountEmployeesOlderThan(int year, int expectedResult) const;
	bool TestGetSalaryOfEmployee(std::string nickname, double expectedResult) const; 
	bool TestGetOldestEmployee(std::string expectedNickname) const;
	bool TestPrintAll() const;

private:
	ICompany* m_company;

	void ErrorMsg(std::string msg) const;
};
#endif //CLIENT_H