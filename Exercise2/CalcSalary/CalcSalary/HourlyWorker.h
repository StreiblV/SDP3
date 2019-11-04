#ifndef HOURLYWORKER_H
#define HOURLYWORKER_H

#include "Employee.h"
#include <string>

class HourlyWorker : public Employee {
public:
	virtual wBase GetType() const override;
	virtual double Salary() const override;

	void SetProducedPieces(size_t const pieces);
	std::size_t GetProdPieces() const;

	void SetSoldPieces(size_t const pieces);
	std::size_t GetSoldPieces() const;


	void SetWorkingHours(double const hours);
	double GetWorkingHours() const;

	void SetHourlyWage(double const wage);
	double GetHourlyWage() const;

	void SetWagePPiece(double const wage);
	double GetWagePPiece() const;

	friend std::ostream& operator <<(std::ostream& ost, HourlyWorker const& worker);

private:
	size_t m_soldPieces;
	size_t m_prodPieces;
	double m_workingHours;

	double m_hourlyWage;
	double m_wagePPiece;
};
#endif //HOURLYWORKER_H
