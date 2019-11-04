#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"
#include <string>

class HourlyWorker {
public:
	virtual std::string GetType() const override;

	virtual void SetProducedPieces() override;
	virtual void SetSoldPieces() override;
	virtual std::size_t GetProdPieces() const override;
	virtual std::size_t GetSoldPieces() const override;

private:
	size_t m_soldPieces;
	size_t m_prodPieces;
	double workingHours;
};
#endif //HOURLYWORKER_H
