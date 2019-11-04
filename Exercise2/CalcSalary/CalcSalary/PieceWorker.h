#ifndef PIECEWORKER_H
#define PIECEWORKER_H
#include <string>

#include "Employee.h"

class PieceWorker {
	virtual std::string GetType() const override;

	virtual void SetProducedPieces() override;
	virtual void SetSoldPieces() override;
	virtual std::size_t GetProdPieces() const override;
	virtual std::size_t GetSoldPieces() const override;

private:
	size_t prodPieces;
};

#endif //PIECEWORKER_H
