/* ______________________________________________________________________
| Workfile : Client.cpp
| Description : [ SOURCE ] Class for the Client to act with an Company
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Client.h"

Client::Client(ICompany* const company) {
	m_company = company;
}

bool Client::TestCompanyName(std::string expectedName) const{
	std::string name = m_company->GetCompanyName();
	if (name == expectedName) {
		return true;
	}
	else {
		ErrorMsg("Company Name was wrong");
		return false;
	}
}
bool Client::TestCompanyLocation(std::string expectedLocation) const {
	std::string name = m_company->GetCompanyLocation();
	if (name == expectedLocation) {
		return true;
	}
	else {
		ErrorMsg("Company Location was wrong");
		return false;
	}
}
bool Client::TestFindEmployeeByNickname(std::string nickname) const {
	m_company->GetEmployee(nickname);
	return true;
}

bool Client::TestCountEmployees(int expectedResult) const {
	int currEmployees = m_company->CountEmployees();
	if (expectedResult == currEmployees) {
		return true;
	}
	else {
		ErrorMsg("Number of employees was wrong");
		return false;
	}
}

bool Client::TestCountEmployeesByType(wBase type, int expectedResult) const {
	int currEmployees = m_company->CountEmployees(type);
	if (expectedResult == currEmployees) {
		return true;
	}
	else {
		ErrorMsg("Numbers of employees by the same type was wrong");
		return false;
	}
}

bool Client::TestCountTotalProducesPieces(int expectedResult) const {
	int totalProdPieces = m_company->GetProdPieces();
	if (expectedResult == totalProdPieces) {
		return true;
	}
	else {
		ErrorMsg("Numbers of produces pieces was wrong");
		return false;
	}
}

bool Client::TestCountTotalSoldPieces(int expectedResult) const {
	int totalSoldPieces = m_company->GetSoldPieces();
	if (expectedResult == totalSoldPieces) {
		return true;
	}
	else {
		ErrorMsg("Numbers of sold pieces was wrong");
		return false;
	}
}

bool Client::TestCountEmployeesOlderThan(int year, int expectedResult) const {
	int employeesOlderThan = m_company->CountEmployeesOlderThan(year);
	if (expectedResult == employeesOlderThan) {
		return true;
	}
	else {
		ErrorMsg("Numbers of older-than employees was wrong");
		return false;
	}
}

bool Client::TestGetSalaryOfEmployee(std::string nickname, double expectedResult) const {
	double salaryOfEmployee = m_company->GetSalaryOfEmployee(nickname);
	if (expectedResult == salaryOfEmployee) {
		return true;
	}
	else {
		ErrorMsg("Salaray of employee was wrong");
		return false;
	}
}

bool Client::TestGetOldestEmployee(std::string expectedNickname) const {
	std::string nickname = m_company->GetOldestEmployee();
	if (expectedNickname == nickname) {
		return true;
	}
	else {
		ErrorMsg("Finding oldest employee was wrong");
		return false;
	}
}

bool Client::TestPrintAll() const {
	m_company->Print();
	return true;
}

void Client::ErrorMsg(std::string msg) const{
	std::cout << "!Error: " << msg << std::endl;
}