#include "Hexapod.h"

void Hexapod::Info(std::ostream& ost) {
	if (ost.good()) {
		ost << "Hexapod: ";
		Robot::Info(ost);
	}
}
