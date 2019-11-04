#ifndef PIECEWORKER_H
#define PIECEWORKER_H
#include <string>

#include "Employee.h"

class PieceWorker : public Employee {
	virtual wBase GetType() const override;
	virtual double Salary() const override;

	void SetProducedPieces(size_t const pieces);
	std::size_t GetProdPieces() const;

	friend std::ostream& operator <<(std::ostream& ost, PieceWorker const& worker);

private:
	size_t m_prodPieces;
	double m_wagePPiece;
};

#endif //PIECEWORKER_H
