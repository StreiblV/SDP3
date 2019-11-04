#include "Boss.h"

wBase Boss::GetType() const {
	return wBase::Boss;
}

void Boss::SetBaseSalary(double const baseSalary) {
	m_baseSalary = baseSalary;
}

double Boss::GetBaseSalary() const {
	return m_baseSalary;
}
