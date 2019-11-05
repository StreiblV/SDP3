#include "PieceWorker.h"

wBase PieceWorker::GetType() const {
	return wBase::Piece;
}

double PieceWorker::Salary() const {
	return (m_wagePPiece * m_prodPieces);
}

void PieceWorker::SetProducedPieces(size_t const pieces) {
	m_prodPieces = pieces;
}

std::size_t PieceWorker::GetProdPieces() const {
	return m_prodPieces;
}

void PieceWorker::SetSoldPieces(size_t const pieces) {
}

std::size_t PieceWorker::GetSoldPieces() const {
	return 0;
}

void PieceWorker::SetBaseSalary(double const baseSalary) {
}

double PieceWorker::GetBaseSalary() const {
	return 0.0;
}

void PieceWorker::SetWorkingHours(double const hours) {
}

double PieceWorker::GetWorkingHours() const {
	return 0.0;
}

void PieceWorker::SetHourlyWage(double const wage) {
}

double PieceWorker::GetHourlyWage() const {
	return 0.0;
}

void PieceWorker::SetWagePPiece(double const wage) {
}

double PieceWorker::GetWagePPiece() const {
	return 0.0;
}

void PieceWorker::Print() {
	Employee::Print();
	std::cout << "Mitarbeiterklasse: " << this->GetType() << std::endl;
	std::cout << "Stückzahl: " << this->GetProdPieces() << std::endl;
	std::cout << "Stückwert: " << this->GetWagePPiece() << " EUR" << std::endl;
	std::cout << "Gehalt: " << this->Salary() << " EUR" << std::endl;
}
