#ifndef BOSS_H
#define BOSS_H

#include <string>
#include "Employee.h"

class Boss : public Employee {
public:
	virtual wBase GetType() const override;
	virtual double Salary() const override;

	void SetBaseSalary(double const baseSalary);
	double GetBaseSalary() const;

	friend std::ostream& operator <<(std::ostream& ost, Employee const&);

private:
	double m_baseSalary;
};

#endif //BOSS_H