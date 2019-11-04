#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <time.h>
#include <iostream>
#include <algorithm>

enum class wBase { Boss, Hourly, Piece, Comission };

class Employee {
public:
	typedef struct  {
		size_t day;
		size_t month;
		size_t year;
	} TDate;

	virtual ~Employee();

	virtual wBase GetType() const = 0;	
	virtual double Salary() const = 0;

	virtual void SetProducedPieces(size_t const pieces) = 0;
	virtual std::size_t GetProdPieces() const = 0;

	virtual void SetSoldPieces(size_t const pieces) = 0;
	virtual std::size_t GetSoldPieces() const = 0;


	virtual void SetWorkingHours(double const hours) = 0;
	virtual double GetWorkingHours() const = 0;

	virtual void SetHourlyWage(double const wage) = 0;
	virtual double GetHourlyWage() const = 0;

	virtual void SetWagePPiece(double const wage) = 0;
	virtual double GetWagePPiece() const = 0;

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

	void SetDateOfJoining(TDate const& dateOfJoining);
	void SetDateOfJoining(std::size_t day, std::size_t month, std::size_t year);

	bool operator ==(Employee const&);

private:
	std::string m_firstname;
	std::string m_lastname;
	std::string m_nickname;
	std::string m_SSN;
	TDate m_birthday;
	TDate m_dateOfJoining;

	//private helper methods
	bool isDateValid(TDate const& date);
	bool isSSNValid(std::string const& ssn);
	TDate GetDateOfJoining() const;
	TDate MakeDate(std::size_t day, std::size_t month, std::size_t year);

};

#endif //EMPLOYEE_H
