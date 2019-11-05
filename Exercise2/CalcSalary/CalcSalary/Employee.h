#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "Object.h"
#include <string>
#include <time.h>
#include <iostream>
#include <algorithm>

enum class wBase { Boss, Hourly, Piece, Comission };
std::ostream& operator<<(std::ostream& ost, wBase const& base);

class Employee : public Object {
public:
	//struct to save dates
	typedef struct  {
		size_t day;
		size_t month;
		size_t year;
	} TDate;
	//Overloaded output-operator
	friend std::ostream& operator<<(std::ostream& ost, TDate const& date);
	Employee() = default;

	//returns type of derived class
	virtual wBase GetType() const = 0;	
	
	//returns specific salary (depends on type)
	virtual double Salary() const = 0;

	//pure virtual Getter/Setter Methods; Getter return 0 if requested value is not contained
	//in the derived class!
	virtual void SetProducedPieces(size_t const pieces) = 0;
	virtual std::size_t GetProdPieces() const = 0;

	virtual void SetSoldPieces(size_t const pieces) = 0;
	virtual std::size_t GetSoldPieces() const = 0;

	virtual void SetBaseSalary(double const baseSalary) = 0;
	virtual double GetBaseSalary() const = 0;	

	virtual void SetWorkingHours(double const hours) = 0;
	virtual double GetWorkingHours() const = 0;

	virtual void SetHourlyWage(double const wage) = 0;
	virtual double GetHourlyWage() const = 0;

	virtual void SetWagePPiece(double const wage) = 0;
	virtual double GetWagePPiece() const = 0;

	//Prints Base and Derived Class
	virtual void Print();

	//Getter/Setter for Baseclass
	void SetFirstname(std::string const& firstname);
	std::string GetFirstname();

	void SetLastname(std::string const& lastname);
	std::string GetLastname() const;

	void SetNickname(std::string const& nickname);
	std::string GetNickname() const;
	
	void setSSN(std::string const& ssn);
	std::string GetSSN() const;

	void SetBirthday(TDate const& birthday);
	TDate GetBirthday() const;

	TDate GetDateOfJoining() const;
	void SetDateOfJoining(TDate const& dateOfJoining);
	void SetDateOfJoining(std::size_t day, std::size_t month, std::size_t year);

	//overloaded ==-Operator (nickname is unique)
	bool operator ==(Employee const&);

private:
	std::string m_firstname;
	std::string m_lastname;
	std::string m_nickname;
	std::string m_SSN;
	TDate m_birthday;
	TDate m_dateOfJoining;

	//returns true if Date-format is valid and not in the future
	bool isDateValid(TDate const& date);

	//returns true if the string contains only numbers and is 10 digits long
	bool isSSNValid(std::string const& ssn);

	//returns the created struct based on the given values
	TDate MakeDate(std::size_t day, std::size_t month, std::size_t year);

};

#endif //EMPLOYEE_H
