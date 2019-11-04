#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee {
public:
	virtual std::string GetType() const = 0;

	virtual void SetProducedPieces() = 0;
	virtual void SetSoldPieces() = 0;

	virtual std::size_t GetProdPieces() const = 0;
	virtual std::size_t GetSoldPieces() const = 0;
	
	std::string GetNickname() const;

	double Salary() const;


private:
	std::string m_firstname;
	std::string m_lastname;
	std::string m_nickname;
	std::string m_SSN;
	std::string m_birthday;
	std::string m_dateOfJoining;
	double m_salary;
};


#endif //EMPLOYEE_H
