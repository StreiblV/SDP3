#pragma once
#include "ICompany.h"

class Client {

public:
	Client(ICompany* const company);

private:
	ICompany* m_company;

	bool TestCompanyName(std::string expectedName) const;
	bool TestCompanyLocation(std::string expectedLocation) const;
	bool TestFindEmployeeByNickname() const;
	bool TestFindEmployeeByBirthday() const;
};