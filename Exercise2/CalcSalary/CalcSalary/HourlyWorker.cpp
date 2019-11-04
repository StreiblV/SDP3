#include "HourlyWorker.h"

wBase HourlyWorker::GetType() const {
	return wBase::Hourly;
}

double HourlyWorker::Salary() const {
	double tmpWage;
	tmpWage = m_workingHours * m_hourlyWage + m_prodPieces * m_wagePPiece;
	return tmpWage;
}

void HourlyWorker::SetProducedPieces(size_t const pieces) {
	m_prodPieces = pieces;
}

void HourlyWorker::SetSoldPieces(size_t const pieces) {
	m_soldPieces = pieces;
}

void HourlyWorker::SetWorkingHours(double const hours) {
	m_workingHours = hours;
}

std::size_t HourlyWorker::GetProdPieces() const {
	return m_prodPieces;
}

std::size_t HourlyWorker::GetSoldPieces() const {
	return m_soldPieces;
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
	m_wagePPiece = wage;
}

double HourlyWorker::GetWagePPiece() const {
	return m_wagePPiece;
}
