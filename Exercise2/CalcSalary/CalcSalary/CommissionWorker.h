#ifndef COMISSIONWORKER_H
#define COMISSIONWORKER_H

#include <string>

#include "Employee.h"


class CommissionWorker : public Employee {
public:
	CommissionWorker() = default;
	virtual wBase GetType() const override;
	virtual double Salary() const override;

	virtual void SetSoldPieces(size_t const pieces) override;
	virtual std::size_t GetSoldPieces() const override;

	void SetBaseSalary(double const baseSalary);
	double GetBaseSalary() const;

	virtual void Print() override;



private:
	size_t m_soldPieces;
	double m_wagePPiece;

	double m_baseSalary;
};
#endif //COMISSIONWORKER_H
