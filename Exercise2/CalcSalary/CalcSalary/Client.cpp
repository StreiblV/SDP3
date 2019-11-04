#include "Client.h"

Client::Client(ICompany* const company) {
	m_company = company;
}

bool Client::TestCompanyName(std::string expectedName) const{
	std::string name = m_company->GetCompanyName();
	if (name != expectedName) {
		return false;
	}
	else {
		return true;
	}
}
bool Client::TestCompanyLocation(std::string expectedLocation) const {
	std::string name = m_company->GetCompanyLocation();
	if (name != expectedLocation) {
		return false;
	}
	else {
		return true;
	}
}
bool Client::TestFindEmployeeByNickname() const {
	return false;
}

bool Client::TestFindEmployeeByBirthday() const {
	return false;
}