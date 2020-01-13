#include "Wheelbot.h"

void Wheelbot::Info(std::ostream& ost) {
	if (ost.good()) {
		ost << "Wheelbot: ";
		Robot::Info(ost);
	}
}
