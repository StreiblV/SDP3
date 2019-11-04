#include "Boss.h"

wBase Boss::GetType() const {
	return wBase::Boss;
}

double Boss::Salary() const {
	return m_baseSalary;
}

void Boss::SetBaseSalary(double const baseSalary) {
	m_baseSalary = baseSalary;
}

double Boss::GetBaseSalary() const {
	return m_baseSalary;
}
