#include "HourlyWorker.h"

wBase HourlyWorker::GetType() const {
	return wBase::Hourly;
}

double HourlyWorker::Salary() const {
	double tmpWage;
	tmpWage = m_workingHours * m_hourlyWage;
	return tmpWage;
}

void HourlyWorker::SetProducedPieces(size_t const pieces) {
}

void HourlyWorker::SetSoldPieces(size_t const pieces) {
}

void HourlyWorker::SetWorkingHours(double const hours) {
	m_workingHours = hours;
}

std::size_t HourlyWorker::GetProdPieces() const {
	return 0;
}

std::size_t HourlyWorker::GetSoldPieces() const {
	return 0;
}

double HourlyWorker::GetWorkingHours() const {
	return m_workingHours;
}

void HourlyWorker::SetHourlyWage(double const wage) {
	m_hourlyWage = wage;
}

double HourlyWorker::GetHourlyWage() const {
	return m_hourlyWage;
}

void HourlyWorker::SetWagePPiece(double const wage) {
}

double HourlyWorker::GetWagePPiece() const {
	return 0;
}

void HourlyWorker::Print() {
	std::cout << "Mitarbeiterklasse: " << this->GetType() << std::endl;
	std::cout << "Arbeitsstunden: " << this->GetWorkingHours() << std::endl;
	std::cout << "Stundenlohn: " << this->GetHourlyWage() << " EUR" << std::endl;
	std::cout << "Gehalt: " << this->Salary() << " EUR" << std::endl;
}
