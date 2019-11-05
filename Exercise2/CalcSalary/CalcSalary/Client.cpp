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
	//get company name and compare with expected name
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
	//get company location and compare with expected location
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
	//search for employee by nickname and print it
	m_company->GetEmployee(nickname);
	return true;
}

bool Client::TestCountEmployees(int expectedResult) const {
	//get number of employees and compare with expected result
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
	//get number of employees of specific type and compare with expected result
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
	//get total produced pieces and compare with expected result
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
	//get total sold pieces and compare with expected result
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
	//get number of employees older than year and compare with expected result
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
	//get salary of employee and compare with expected result
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
	//get nickname of oldest employee compare with expected nickname
	std::string nickname = m_company->GetOldestEmployee();
	if (expectedNickname == nickname) {
		return true;
	}
	else {
		ErrorMsg("Finding oldest employee was wrong");
		return false;
	}
}

bool Client::TestLongestTimeInCompany(std::string expectedNickname) const {
	//get nickname of oldest employee compare with expected nickname
	std::string nickname = m_company->GetEmployeeWithLongestTimeInCompany();
	if (expectedNickname == nickname) {
		return true;
	}
	else {
		ErrorMsg("Finding employee which is in the company for the longest time was wrong");
		return false;
	}
}

bool Client::TestPrintAll() const {
	//print everything
	m_company->Print();
	return true;
}

void Client::ErrorMsg(std::string msg) const{
	//outputs the error message
	std::cout << "!!!!!! Error: " << msg << std::endl;
}