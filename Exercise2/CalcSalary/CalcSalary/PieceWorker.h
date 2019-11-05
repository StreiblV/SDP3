/* ______________________________________________________________________
| Workfile : PieceWorker.h
| Description : [ HEADER ] Derived Class PieceWorker
| Name : Daniel Weyrer					PKZ : S1820306044
| Date : 04.11.2019
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef PIECEWORKER_H
#define PIECEWORKER_H
#include <string>

#include "Employee.h"

class PieceWorker : public Employee {
public:
	PieceWorker() : m_prodPieces{ 0 }, m_wagePPiece{ 0 } {}

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

	virtual void SetHourlyWage(double const wage) override;
	virtual double GetHourlyWage() const override;

	virtual void SetWagePPiece(double const wage) override;
	virtual double GetWagePPiece() const override;

	virtual void Print() override;


private:
	std::size_t m_prodPieces;
	double m_wagePPiece;
};

#endif //PIECEWORKER_H
