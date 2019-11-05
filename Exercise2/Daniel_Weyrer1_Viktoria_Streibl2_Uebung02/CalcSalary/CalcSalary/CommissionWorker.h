/* ______________________________________________________________________
| Workfile : CommssionWorker.h
| Description : [ HEADER ] Derived Class ComissionWorker
| Name : Daniel Weyrer					PKZ : S1820306044
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef COMISSIONWORKER_H
#define COMISSIONWORKER_H

#include <string>

#include "Employee.h"


class CommissionWorker : public Employee {
public:
	CommissionWorker() : m_soldPieces{ 0 }, m_wagePPiece{ 0 }, m_baseSalary{ 0 }{}
	virtual wBase GetType() const override;
	virtual double Salary() const override;

	virtual void SetSoldPieces(size_t const pieces) override;
	virtual std::size_t GetSoldPieces() const override;

	virtual void SetBaseSalary(double const baseSalary) override;
	virtual double GetBaseSalary() const override;

	virtual void SetProducedPieces(size_t const pieces) override;
	virtual std::size_t GetProdPieces() const override;

	virtual void SetWorkingHours(double const hours) override;
	virtual double GetWorkingHours() const override;

	virtual void SetHourlyWage(double const wage);
	virtual double GetHourlyWage() const;

	virtual void SetWagePPiece(double const wage);
	virtual double GetWagePPiece() const;

	virtual void Print() override;

private:
	size_t m_soldPieces;
	double m_wagePPiece;

	double m_baseSalary;
};
#endif //COMISSIONWORKER_H
