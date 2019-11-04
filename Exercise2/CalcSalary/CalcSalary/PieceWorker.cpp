#include "PieceWorker.h"

wBase PieceWorker::GetType() const {
	return wBase::Piece;
}

double PieceWorker::Salary() const {
	return m_wagePPiece * m_prodPieces;
}

void PieceWorker::SetProducedPieces(size_t const pieces) {
	m_prodPieces = pieces;
}

std::size_t PieceWorker::GetProdPieces() const {
	return m_prodPieces;
}
