#pragma once

#include <string>
#include <list>

#include "Employee.h"

class Company
{

public:

private:
	std::string m_name;
	std::string m_location;
	std::list<Employee> m_employees;
};

