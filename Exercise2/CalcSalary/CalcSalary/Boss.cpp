#include "Boss.h"

Boss::Boss(double const baseSalary) {
	m_baseSalary = baseSalary;
}

wBase Boss::GetType() const {
	return wBase::Boss;
}

double Boss::Salary() const {
	return m_baseSalary;
}

void Boss::SetBaseSalary(double const baseSalary) {
	m_baseSalary = baseSalary;
}

double Boss::GetBaseSalary() const {
	return m_baseSalary;
}

void Boss::SetProducedPieces(size_t const pieces) {
}

std::size_t Boss::GetProdPieces() const {
	return 0;
}

void Boss::SetSoldPieces(size_t const pieces) {
}

std::size_t Boss::GetSoldPieces() const {
	return 0;
}

void Boss::SetWorkingHours(double const hours) {
}

double Boss::GetWorkingHours() const {
	return 0.0;
}

void Boss::SetHourlyWage(double const wage) {
}

double Boss::GetHourlyWage() const {
	return 0.0;
}

void Boss::SetWagePPiece(double const wage) {
}

double Boss::GetWagePPiece() const {
	return 0.0;
}

void Boss::Print() {
	Employee::Print();
	std::cout << "Mitarbeiterklasse: " << this->GetType() << std::endl;
	std::cout << "Gehalt: " << this->Salary() <<" EUR" << std::endl;
}
