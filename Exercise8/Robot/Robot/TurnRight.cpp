#include "TurnRight.h"

void TurnRight::Execute() {
	DIR tmp = m_robot->GetDirection();
	switch (tmp) {
	case DIR::NORTH:
		tmp = DIR::EAST;
		break;
	case DIR::SOUTH:
		tmp = DIR::WEST;
		break;
	case DIR::EAST:
		tmp = DIR::SOUTH;
		break;
	case DIR::WEST:
		tmp = DIR::NORTH;
		break;
	default:
		break;
	}
	m_robot->SetDirection(tmp);
}

void TurnRight::Unexecute() {
	DIR tmp = m_robot->GetDirection();
	switch (tmp) {
	case DIR::NORTH:
		tmp = DIR::WEST;
		break;
	case DIR::SOUTH:
		tmp = DIR::EAST;
		break;
	case DIR::EAST:
		tmp = DIR::NORTH;
		break;
	case DIR::WEST:
		tmp = DIR::SOUTH;
		break;
	default:
		break;
	}
	m_robot->SetDirection(tmp);
}
