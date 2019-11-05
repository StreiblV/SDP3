#ifndef BOSS_H
#define BOSS_H

#include <string>
#include "Employee.h"

class Boss : public Employee {
public:
	Boss() : m_baseSalary{ 0 } {}
	Boss(double const baseSalary);
	virtual ~Boss() override = default;

	virtual wBase GetType() const override;
	virtual double Salary() const override;

	virtual void SetBaseSalary(double const baseSalary) override;
	virtual double GetBaseSalary() const override;	

	virtual void SetProducedPieces(size_t const pieces) override;
	virtual std::size_t GetProdPieces() const override;	

	virtual void SetSoldPieces(size_t const pieces) override;
	virtual std::size_t GetSoldPieces() const override;


	virtual void SetWorkingHours(double const hours) override;
	virtual double GetWorkingHours() const override;

	virtual void SetHourlyWage(double const wage) override;
	virtual double GetHourlyWage() const override;

	virtual void SetWagePPiece(double const wage) override;
	virtual double GetWagePPiece() const override;

	virtual void Print() override;


private:
	double m_baseSalary;
};

#endif //BOSS_H
