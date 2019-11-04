#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"
#include <string>

class HourlyWorker : public Employee {
public:
	virtual wBase GetType() const override;
	virtual double Salary() const override;

	virtual void SetProducedPieces(size_t const pieces) override;
	virtual std::size_t GetProdPieces() const override;

	virtual void SetSoldPieces(size_t const pieces) override;
	virtual std::size_t GetSoldPieces() const override;


	virtual void SetWorkingHours(double const hours) override;
	virtual double GetWorkingHours() const override;

	virtual void SetHourlyWage(double const wage);
	virtual double GetHourlyWage() const;

	virtual void SetWagePPiece(double const wage);
	virtual double GetWagePPiece() const;

	friend std::ostream& operator <<(std::ostream& ost, HourlyWorker const& worker);

private:
	size_t m_soldPieces;
	size_t m_prodPieces;
	double m_workingHours;

	double m_hourlyWage;
	double m_wagePPiece;
};
#endif //HOURLYWORKER_H
