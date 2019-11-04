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
			//(**itList).Print() --Daniel
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
		//sumSoldPieces += (**itList).GetSoldPieces(); --Daniel
	}
	return sumSoldPieces;
}

int Company::GetProdPieces() {
	int sumProdPieces = 0;
	list<EUptr>::const_iterator itList;
	for (itList = m_employees.cbegin(); itList != m_employees.cend(); ++itList) {
		//sumProdPieces += (**itList).GetProdPieces(); --Daniel
	}
	return sumProdPieces;
}

int Company::CountEmployees() {
	return m_employees.size();
}

int Company::CountEmployess(Employee::TDate birthday) {
	auto PredBirthday = [birthday](EUptr const& e) {
		return (birthday.year == (*e).GetBirthday().year);
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
	catch (bad_alloc const& ex) {
		cerr << " memory allocation : " << ex.what() << endl;
	}
}

EIter Company::FindEmployee(string nickname) {
	auto PredBirthday = [nickname](unique_ptr<Employee> const& e) {
		return (nickname == (*e).GetNickname());
	};
	
	return find_if(m_employees.begin(), m_employees.end(), PredBirthday);
}