/* ______________________________________________________________________
| Workfile : Company.cpp
| Description : [ SOURCE ] Class Company to store all data
| Name : Viktoria Streibl			PKZ : S1810306013
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */
#include "Company.h"

using namespace std;

Company::Company(std::string const name, std::string const location) {
	m_name = name;
	m_location = location;
}

string Company::GetCompanyName() {
	return m_name;
}
string Company::GetCompanyLocation() {
	return m_location;
}

void Company::GetEmployee(std::string const nickname) {
	EIter itList;
	for (itList = m_employees.cbegin(); itList != m_employees.cend(); ++itList) {
		if (nickname == (**itList).GetNickname()) {
			//(**itList).Print(); --Daniel
		}
	}
}

void Company::GetEmployee(wBase type){
	EIter itList;
	for (itList = m_employees.cbegin(); itList != m_employees.cend(); ++itList) {
		if (type == (**itList).GetType()) {
			//(**itList).Print() --Daniel
		}
	}
}

int Company::GetSoldPieces() {
	int sumSoldPieces = 0;

	list<EUptr>::const_iterator itList;
	for (itList = m_employees.cbegin(); itList != m_employees.cend(); ++itList) {
		sumSoldPieces += (**itList).GetSoldPieces();
	}
	return sumSoldPieces;
}

int Company::GetProdPieces() {
	int sumProdPieces = 0;
	list<EUptr>::const_iterator itList;
	for (itList = m_employees.cbegin(); itList != m_employees.cend(); ++itList) {
		sumProdPieces += (**itList).GetProdPieces();
	}
	return sumProdPieces;
}

double Company::GetSalaryOfEmployee(std::string nickname) {
	EIter iter = FindEmployee(nickname);
	return (**iter).Salary();
}

string Company::GetOldestEmployee() {
	list<EUptr>::const_iterator itList = m_employees.cbegin();
	string nickname = (**itList).GetNickname();
	Employee::TDate birthday = (**itList).GetBirthday();
	for (itList = ++m_employees.cbegin(); itList != m_employees.cend(); ++itList) {
		if ((**itList).GetBirthday().year == birthday.year) {
			if ((**itList).GetBirthday().month == birthday.month) {
				if ((**itList).GetBirthday().day > birthday.day) {
					nickname = (**itList).GetNickname();
					birthday = (**itList).GetBirthday();
				}
			}
			else if ((**itList).GetBirthday().year > birthday.year) {
				nickname = (**itList).GetNickname();
				birthday = (**itList).GetBirthday();
			}
		}
		else if ((**itList).GetBirthday().year > birthday.year) {
			nickname = (**itList).GetNickname();
			birthday = (**itList).GetBirthday();
		}
	}

	return nickname;
}

int Company::CountEmployees() {
	return m_employees.size();
}

int Company::CountEmployees(wBase type) {
	auto PredType = [type](EUptr const& e) {
		return (type == (*e).GetType());
	};

	return count_if(m_employees.begin(), m_employees.end(), PredType);
}

int Company::CountEmployeesOlderThan(int year){
	auto PredBirthday = [year](EUptr const& e) {
		return (year <= (*e).GetBirthday().year);
	};

	return count_if(m_employees.begin(), m_employees.end(), PredBirthday);
}

void Company::Print() {
	list<EUptr>::const_iterator itList;
	for (itList = m_employees.cbegin(); itList != m_employees.cend(); ++itList) {
		cout << (**itList).GetFirstname();
		cout << "*******************************************" << endl;
		cout << m_name <<", " << m_location << endl;
		cout << "*******************************************" << endl;
		cout << "Datenblatt" << endl;	
		cout << "---------------" << endl;

		//(**itList).Print() -- Daniel

		cout << "-------------------------------------------" << endl;
		cout << "v1.0 Oktober 2019" << endl;
		cout << "-------------------------------------------" << endl;
	}
}

void Company::AddEmployee(EUptr e) {
	m_employees.emplace_back(move(e));
}

void Company::DeleteEmployee(EUptr e) {
	try {
		std::string nickname = (*e).GetNickname();
		EIter iter = FindEmployee(nickname);

		if (iter == m_employees.cend()) {
			throw exception(" Delete failed : The employee is not registered in this company!");
		}
		else {
			m_employees.erase(iter);
		}
	}
	catch (exception const& ex) {
		cerr << ex.what() << endl;
	}
}

EIter Company::FindEmployee(string nickname) {
	auto PredBirthday = [nickname](unique_ptr<Employee> const& e) {
		return (nickname == (*e).GetNickname());
	};
	
	return find_if(m_employees.begin(), m_employees.end(), PredBirthday);
}