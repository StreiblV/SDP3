/* ______________________________________________________________________
| Workfile : CommissionWorker.cpp
| Description : [ SOURCE ] Derived Class CommissionWorker
| Name : Daniel Weyrer					PKZ : S1820306044
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */


#include "CommissionWorker.h"

wBase CommissionWorker::GetType() const {
	return wBase::Comission;
}

double CommissionWorker::Salary() const {
	return (m_baseSalary + (m_wagePPiece * m_soldPieces));
}

void CommissionWorker::SetSoldPieces(size_t const pieces) {
	m_soldPieces = pieces;
}

std::size_t CommissionWorker::GetSoldPieces() const {
	return m_soldPieces;
}

void CommissionWorker::SetBaseSalary(double const baseSalary) {
	m_baseSalary = baseSalary;
}

double CommissionWorker::GetBaseSalary() const {
	return m_baseSalary;
}

void CommissionWorker::SetProducedPieces(size_t const pieces) {
}

std::size_t CommissionWorker::GetProdPieces() const {
	return 0;
}

void CommissionWorker::SetWorkingHours(double const hours) {
}

double CommissionWorker::GetWorkingHours() const {
	return 0.0;
}

void CommissionWorker::SetHourlyWage(double const wage) {
}

double CommissionWorker::GetHourlyWage() const {
	return 0.0;
}

void CommissionWorker::SetWagePPiece(double const wage) {
	m_wagePPiece = wage;
}

double CommissionWorker::GetWagePPiece() const {
	return m_wagePPiece;
}

void CommissionWorker::Print() {
	Employee::Print();
	std::cout << "Mitarbeiterklasse: " << this->GetType() << std::endl;
	std::cout << "Grundgehalt: " << this->GetBaseSalary() << " EUR" << std::endl;
	std::cout << "Provision: " << (this->GetSoldPieces() * this->GetWagePPiece()) << std::endl;
	std::cout << "Gehalt: " << this->Salary() << " EUR" << std::endl;
}

