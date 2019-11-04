#include "CommissionWorker.h"

wBase CommissionWorker::GetType() const {
	return wBase::Comission;
}

double CommissionWorker::Salary() const {
	return m_baseSalary + m_wagePPiece * m_soldPieces;
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

