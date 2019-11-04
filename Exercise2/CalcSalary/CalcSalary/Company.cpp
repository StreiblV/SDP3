#include "Company.h"

using namespace std;

Company::Company(std::string name, std::string location) {
	m_name = name;
	m_location = location;
}

string Company::GetCompanyName() {
	return m_name;
}
string Company::GetCompanyLocation() {
	return m_location;
}

Employee* Company::GetEmployee(std::string nickname) {
	for (Employee emp : m_employees) {
		if (nickname == emp.GetNickname()) {
			return emp;
		}
	};
	return new Employee();
}

//Employee* Company::GetEmployee(Type type){}

int Company::GetSoldPieces() {
	int sumSoldPieces = 0;
	for (Employee emp : m_employees) {
		sumSoldPieces += emp.GetSoldPieces();
	}
	return sumSoldPieces;
}

int Company::GetProdPieces() {
	int sumProdPieces = 0;
	for (Employee emp : m_employees) {
		sumProdPieces += emp.GetProdPieces();
	}
	return sumProdPieces;
}

int Company::CountEmployees() {
	return m_employees.size();
}

//int Company::CountEmployess(Date birthday) {}

void Company::Print() {
	for (Employee emp : m_employees) {
		//cout << emp;
	}
}

void Company::AddEmployee(Employee e) {
	m_employees.push_back(e);
}

void Company::DeleteEmployee(Employee e) {
	for (Employee emp : m_employees) {
		/*if (emp == e) {
			//delete
		}*/
	}
}