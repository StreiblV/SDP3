#ifndef COMISSIONWORKER_H
#define COMISSIONWORKER_H

#include <string>

#include "Employee.h"


class CommissionWorker : public Employee {
public:
	virtual wBase GetType() const override;
	virtual double Salary() const override;

	void SetSoldPieces(size_t const pieces);
	std::size_t GetSoldPieces() const;

	void SetBaseSalary(double const baseSalary);
	double GetBaseSalary() const;

	friend std::ostream& operator <<(std::ostream& ost, CommissionWorker const& worker);


private:
	size_t m_soldPieces;
	double m_wagePPiece;

	double m_baseSalary;
};
#endif //COMISSIONWORKER_H
