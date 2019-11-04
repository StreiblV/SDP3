#ifndef COMISSIONWORKER_H
#define COMISSIONWORKER_H

#include <string>

#include "Employee.h"


class CommissionWorker : public Employee {
public:
	virtual wBase GetType() const override;

	virtual void SetProducedPieces() override;
	virtual void SetSoldPieces() override;

	virtual std::size_t GetProdPieces() const override;
	virtual std::size_t GetSoldPieces() const override;

	void SetBaseSalary(double const& baseSalary);
	double GetBaseSalary() const;

private:
	size_t m_soldPieces;
	double m_baseSalary;
};
#endif //COMISSIONWORKER_H
