/* ______________________________________________________________________
| Workfile : Testdriver.cpp
| Description : [ SOURCE ] Main File for testing the program
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Client.h"
#include "Company.h"

#include "Boss.h"
#include "CommissionWorker.h"
#include "HourlyWorker.h"
#include "PieceWorker.h"

void PrintTestTitle(std::string const subtitle);
void TestLinzAG(Company* const linzag);
void TestSequality(Company* const sequality);
void TestTractive(Company* const tractive);

int main() {
	Company linzag("Linz AG", "Linz");
	Company sequality("Sequality GmbH", "Hagenberg");
	Company tractive("Tractive", "Pasching");

	//Boss* boss = new Boss();
	//linzag.AddEmployee(std::make_unique<Employee>(&e));

	TestLinzAG(&linzag);
	TestSequality(&sequality);
	TestTractive(&tractive);



	return 0;
}

void PrintTestTitle(std::string const subtitle) {
	std::cout << std::endl;
	std::cout << "###############################" << std::endl;
	std::cout << subtitle << std::endl;
	std::cout << "###############################" << std::endl;
}

void TestLinzAG(Company* const linzag) {
	PrintTestTitle("Client test for Linz AG");

	ICompany* comp = dynamic_cast<ICompany*>(&(*linzag));
	Client client_linzAG(comp);
	bool isLinzAGValid = true;

	isLinzAGValid = isLinzAGValid ? client_linzAG.TestCompanyName("Linz AG") : false;
	isLinzAGValid = isLinzAGValid ? client_linzAG.TestCompanyLocation("Linz") : false;
	//isLinzAGValid = isLinzAGValid ? client_linzAG.TestFindEmployeeByBirthday() : false;

	if (isLinzAGValid) {
		std::cout << "Everything OK..." << std::endl;
	}
	else {
		std::cout << "Something failed..." << std::endl;
	}

}
void TestSequality(Company* const sequality) {

	PrintTestTitle("Client test for Sequality GmbH");

	ICompany* comp = dynamic_cast<ICompany*>(&(*sequality));
	Client client_sequality(comp);
	bool isSequalityValid = true;

	isSequalityValid = isSequalityValid ? client_sequality.TestCompanyName("Sequality GmbH") : false;
	isSequalityValid = isSequalityValid ? client_sequality.TestCompanyLocation("Hagenberg") : false;

	if (isSequalityValid) {
		std::cout << "Everything OK..." << std::endl;
	}
	else {
		std::cout << "Something failed..." << std::endl;
	}
}
void TestTractive(Company* const tractive) {
	PrintTestTitle("Client test for Tractive");

	ICompany* comp = dynamic_cast<ICompany*>(&(*tractive));
	Client client_tractive(comp);
	bool isTractiveValid = true;

	isTractiveValid = isTractiveValid ? client_tractive.TestCompanyName("Tractive") : false;
	isTractiveValid = isTractiveValid ? client_tractive.TestCompanyLocation("Pasching") : false;

	if (isTractiveValid) {
		std::cout << "Everything OK..." << std::endl;
	}
	else {
		std::cout << "Something failed..." << std::endl;
	}
}