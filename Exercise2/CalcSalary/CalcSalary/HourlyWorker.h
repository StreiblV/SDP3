#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"
#include <string>

class HourlyWorker : public Employee {
public:
	HourlyWorker() : m_workingHours{ 0 }, m_hourlyWage{ 0 }{}

	virtual wBase GetType() const override;
	virtual double Salary() const override;

	virtual void SetProducedPieces(size_t const pieces) override;
	virtual std::size_t GetProdPieces() const override;

	virtual void SetSoldPieces(size_t const pieces) override;
	virtual std::size_t GetSoldPieces() const override;

	virtual void SetBaseSalary(double const baseSalary) override;
	virtual double GetBaseSalary() const override;

	virtual void SetWorkingHours(double const hours) override;
	virtual double GetWorkingHours() const override;

	virtual void SetHourlyWage(double const wage);
	virtual double GetHourlyWage() const;

	virtual void SetWagePPiece(double const wage);
	virtual double GetWagePPiece() const;

	virtual void Print() override;


private:
	double m_workingHours;
	double m_hourlyWage;
};
#endif //HOURLYWORKER_H
