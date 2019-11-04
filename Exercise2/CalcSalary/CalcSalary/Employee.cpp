#include "Employee.h"

size_t static const minimumAge = 15;


void Employee::SetNickname(std::string const& nickname) {
	m_nickname = nickname;
}

std::string Employee::GetNickname() const {
	return m_nickname;
}

void Employee::setSSN(std::string const& ssn) {
	try {
		if (isSSNValid(ssn)) {
			m_SSN = ssn;
		}
		else {
			throw("SSN invalid!");
		}
	}
	catch (std::exception const& ex) {
		std::cerr << "SSN-Exception: " << ex.what() << std::endl;
	}
}

std::string Employee::GetSSN() const {
	return m_SSN;
}

void Employee::SetBirthday(Employee::TDate const& birthday) {
	try {
		if (isDateValid(birthday)) {
			time_t now = time(0);
			tm ltm;
			localtime_s(&ltm, &now);
			if ((ltm.tm_year - minimumAge) >= birthday.year && ltm.tm_mon >= birthday.month && ltm.tm_mday >= birthday.day) {
				m_birthday = birthday;
			}
			else {
				throw ("Employee is not allowed to work yet!");
			}
		}
		else {
			throw("Entered date is invalid");
		}
	}
	catch (std::exception const& ex) {
		std::cerr << "Date-Exception: " << ex.what() << std::endl;
	}

}

Employee::TDate Employee::GetBirthday() const {
	return m_birthday;
}

void Employee::SetDateOfJoining(Employee::TDate const& dateOfJoining) {
	try {
		if (isDateValid(dateOfJoining)) {
			m_dateOfJoining = dateOfJoining;
		}
		else {
			throw("Entered Date is invalid");
		}
	}
	catch (std::exception const& ex) {
		std::cerr << "Date-Exception: " << ex.what() << std::endl;
	}
}

void Employee::SetDateOfJoining(std::size_t day, std::size_t month, std::size_t year) {
	SetDateOfJoining(MakeDate(day, month, year));
}

bool Employee::operator==(Employee const& e) {
	return (this->GetNickname() == e.GetNickname());
}

Employee::TDate Employee::MakeDate(std::size_t day, std::size_t month, std::size_t year) {
	TDate tmp;
	tmp.day = day; tmp.month = month; tmp.year = year;
	return tmp;
}

bool Employee::isDateValid(Employee::TDate const& date) {
	//get current date
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);

	//gregorian dates started in 1582
	if (!(1582 <= date.year)) {
		return false;
	}
	if (!(1 <= date.month && date.month <= 12)) {
		return false;
	}
	if (!(1 <= date.day && date.day <= 31)) {
		return false;
	}
	//Months with 30 days
	if ((date.day == 31) && (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)) {
		return false;
	}
	//february has a max of 29 days in a leap year
	if ((date.day == 30) && (date.month == 2)) {
		return false;
	}
	//Leap-day at 29th of february every 4 years, but not every hundredth year (to keep it in sync with earth-rotation)
	if ((date.month == 2) && (date.day == 29) && (date.year % 4 != 0)) {
		return false;
	}
	if ((date.month == 2) && (date.day == 29) && (date.year % 400 == 0)) {
		return true;
	}
	if ((date.month == 2) && (date.day == 29) && (date.year % 100 == 0)) {
		return false;
	}

	//Check if current date is in the past
	if (date.year > ltm.tm_year || date.month > ltm.tm_mon || date.day > ltm.tm_mday) {
		return false;
	}

	return true;
}

std::ostream& operator<<(std::ostream& ost, Employee::TDate const& date) {
	if (ost.good()) {
		ost << date.day << "." << date.month << "." << date.year;
	}
	return ost;
}

std::ostream& operator<<(std::ostream& ost, wBase const& base) {
	if (ost.good()) {
		switch (base) {
		case wBase::Boss: ost << "Boss";
		case wBase::Hourly: ost << "HourlyWorker";
		case wBase::Piece: ost << "PieceWorker";
		case wBase::Comission: ost << "ComissionWorker";
		}
	}
	return ost;
}

bool Employee::isSSNValid(std::string const& ssn) {
	if (ssn.length() != 10) {
		return false;
	}
	auto PredSSN = [](char const c) {return (isdigit(c)); };
	return std::all_of(ssn.cbegin(), ssn.cend(), PredSSN);
}

Employee::TDate Employee::GetDateOfJoining() const {
	return m_dateOfJoining;

}

void Employee::Print() {
	std::cout << "Name: " << this->GetFirstname() << " " << this->GetLastname() << std::endl;
	std::cout << "K�rzel: " << this->GetNickname() << std::endl;
	std::cout << "Sozialversicherungsnummer: " << this->GetSSN() << std::endl;
	std::cout << "Einstiegsjahr: " << this->GetDateOfJoining() << std::endl;
}

void Employee::SetFirstname(std::string const& firstname) {
	m_firstname = firstname;
}

std::string Employee::GetFirstname() {
	return m_firstname;
}

void Employee::SetLastname(std::string const& lastname) {
	m_lastname = lastname;
}

std::string Employee::GetLastname() const {
	return m_lastname;
}
