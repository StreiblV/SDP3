#include "Forward.h"

void Forward::Execute() {
	int posX = m_robot->GetPosX();
	int posY = m_robot->GetPosY();
	switch (m_robot->GetDirection()) {
	case DIR::NORTH:
		posY += m_distance;
		m_robot->SetPosY(posY);
		break;
	case DIR::SOUTH:
		posY -= m_distance;
		m_robot->SetPosY(posY);
		break;
	case DIR::EAST:
		posX += m_distance;
		m_robot->SetPosX(posX);
		break;
	case DIR::WEST:
		posX -= m_distance;
		m_robot->SetPosX(posX);
		break;
	default:
		break;
	}
}

void Forward::Unexecute() {
	m_distance *= -1;
	Execute();
	m_distance *= -1;
}
