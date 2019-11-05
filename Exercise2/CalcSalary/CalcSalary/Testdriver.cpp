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
	//create some companies
	Company linzag("Linz AG", "Linz");
	Company sequality("Sequality GmbH", "Hagenberg");
	Company tractive("Tractive", "Pasching");

	Employee::TDate birthday;
	Employee::TDate joinDate;

	//create some employees
	Boss b;
	b.SetFirstname("Christian");
	b.SetLastname("Grey");
	b.SetBaseSalary(4800);
	birthday.day = 12;
	birthday.month = 1;
	birthday.year = 1972;
	b.SetBirthday(birthday);
	b.SetNickname("CGB");
	b.setSSN("1234512345");
	joinDate.day = 1;
	joinDate.month = 1;
	joinDate.year = 2001;
	linzag.AddEmployee(std::make_unique<Boss>(b));
	sequality.AddEmployee(std::make_unique<Boss>(b));
	tractive.AddEmployee(std::make_unique<Boss>(b));

	CommissionWorker w;
	w.SetFirstname("Viktoria");
	w.SetLastname("Streibl");
	w.SetBaseSalary(2100);
	w.SetSoldPieces(11);
	w.SetWagePPiece(8);
	birthday.day = 29;
	birthday.month = 10;
	birthday.year = 1998;
	w.SetBirthday(birthday);
	w.SetNickname("ViS");
	w.setSSN("1290012900");
	joinDate.day = 1;
	joinDate.month = 1;
	joinDate.year = 2010;
	w.SetDateOfJoining(joinDate);
	linzag.AddEmployee(std::make_unique<CommissionWorker>(w));
	sequality.AddEmployee(std::make_unique<CommissionWorker>(w));

	HourlyWorker hw;
	hw.SetFirstname("Daniel");
	hw.SetLastname("Weyrer");
	hw.SetWorkingHours(80);
	hw.SetHourlyWage(13);
	birthday.day = 17;
	birthday.month = 1;
	birthday.year = 1998;
	hw.SetBirthday(birthday);
	hw.SetNickname("DaW");
	hw.setSSN("7733177331");
	joinDate.day = 1;
	joinDate.month = 1;
	joinDate.year = 2015;
	hw.SetDateOfJoining(joinDate);
	linzag.AddEmployee(std::make_unique<HourlyWorker>(hw));
	tractive.AddEmployee(std::make_unique<HourlyWorker>(hw));

	PieceWorker pw;
	pw.SetFirstname("John");
	pw.SetLastname("Doe");
	pw.SetProducedPieces(10);
	pw.SetWagePPiece(5.0);
	birthday.day = 28;
	birthday.month = 4;
	birthday.year = 1983;
	pw.SetBirthday(birthday);
	pw.SetNickname("JoD");
	pw.setSSN("1230502539");
	joinDate.day = 15;
	joinDate.month = 7;
	joinDate.year = 2003;
	pw.SetDateOfJoining(joinDate);
	linzag.AddEmployee(std::make_unique<PieceWorker>(pw));
	tractive.AddEmployee(std::make_unique<PieceWorker>(pw));

	//test companies
	TestLinzAG(&linzag);
	TestSequality(&sequality);
	TestTractive(&tractive);

	return 0;
}

//print subtile of testcase
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

	//test some functions withs client of linzag
	isLinzAGValid = isLinzAGValid ? client_linzAG.TestCompanyName("Linz AG") : false;
	isLinzAGValid = isLinzAGValid ? client_linzAG.TestCompanyLocation("Linz") : false;
	isLinzAGValid = isLinzAGValid ? client_linzAG.TestCountEmployees(4) : false;
	isLinzAGValid = isLinzAGValid ? client_linzAG.TestFindEmployeeByNickname("DaW") : false;
	isLinzAGValid = isLinzAGValid ? client_linzAG.TestCountEmployeesOlderThan(1990, 2) : false;
	isLinzAGValid = isLinzAGValid ? client_linzAG.TestGetOldestEmployee("CGB") : false;
	isLinzAGValid = isLinzAGValid ? client_linzAG.TestLongestTimeInCompany("CGB") : false;
	client_linzAG.TestPrintAll();

	//check if everything works
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

	//test some functions withs client of sequlity
	isSequalityValid = isSequalityValid ? client_sequality.TestCompanyName("Sequality GmbH") : false;
	isSequalityValid = isSequalityValid ? client_sequality.TestCompanyLocation("Hagenberg") : false;
	isSequalityValid = isSequalityValid ? client_sequality.TestCountEmployeesByType(wBase::Comission, 1) : false;
	isSequalityValid = isSequalityValid ? client_sequality.TestCountTotalSoldPieces(11) : false;
	isSequalityValid = isSequalityValid ? client_sequality.TestGetSalaryOfEmployee("ViS", 2188) : false;
	client_sequality.TestPrintAll();

	//check if everything works
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

	//test some functions withs client of tractive
	isTractiveValid = isTractiveValid ? client_tractive.TestCompanyName("Tractive") : false;
	isTractiveValid = isTractiveValid ? client_tractive.TestCompanyLocation("Pasching") : false;
	isTractiveValid = isTractiveValid ? client_tractive.TestCountTotalProducesPieces(10) : false;
	isTractiveValid = isTractiveValid ? client_tractive.TestGetSalaryOfEmployee("DaW", 1040) : false;
	client_tractive.TestPrintAll();

	//check if everything works
	if (isTractiveValid) {
		std::cout << "Everything OK..." << std::endl;
	}
	else {
		std::cout << "Something failed..." << std::endl;
	}
}