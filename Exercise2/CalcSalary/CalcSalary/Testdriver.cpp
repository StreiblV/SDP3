#include "Client.h"
#include "Company.h"

void PrintTestTitle(std::string subtitle);
void TestLinzAG();
void TestSequality();
void TestTractive();

int main() {
	TestLinzAG();
	TestSequality();
	TestTractive();

	return 0;
}

void PrintTestTitle(std::string subtitle) {
	std::cout << std::endl;
	std::cout << "###############################" << std::endl;
	std::cout << subtitle << std::endl;
	std::cout << "###############################" << std::endl;
}

void TestLinzAG() {
	Company linzag("Linz AG", "Linz");
	PrintTestTitle("Client test for Linz AG");

	ICompany* comp = dynamic_cast<ICompany*>(&linzag);
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

void TestSequality() {
	Company sequality("Sequality GmbH", "Hagenberg");
	PrintTestTitle("Client test for Sequality GmbH");

	ICompany* comp = dynamic_cast<ICompany*>(&sequality);
	Client client_sequality(comp);
	bool isSequalityValid = true;

	if (isSequalityValid) {
		std::cout << "Everything OK..." << std::endl;
	}
	else {
		std::cout << "Something failed..." << std::endl;
	}
}

void TestTractive() {
	Company tractive("Tractive", "Pasching");
	PrintTestTitle("Client test for Tractive");

	ICompany* comp = dynamic_cast<ICompany*>(&tractive);
	Client client_sequality(comp);
	bool isTractiveValid = true;

	if (isTractiveValid) {
		std::cout << "Everything OK..." << std::endl;
	}
	else {
		std::cout << "Something failed..." << std::endl;
	}
}