#ifndef BOSS_H
#define BOSS_H

#include <string>
#include "Employee.h"

class Boss : public Employee {
public:
	virtual std::string GetType() const override;

	virtual void SetProducedPieces() override;
	virtual void SetSoldPieces() override;
	virtual std::size_t GetProdPieces() const override;
	virtual std::size_t GetSoldPieces() const override;

	void SetBaseSalary(double const& baseSalary);
	double GetBaseSalary() const;

private:
	double m_baseSalary;
};

#endif //BOSS_H