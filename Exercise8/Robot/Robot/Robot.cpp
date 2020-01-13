// Robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Robot.h"



void Robot::Info(std::ostream& ost) {
	if (ost.good()) {
		ost << m_name << ", " << "Pos(" << m_posX << "," << m_posY << "), " << "Direction(" << m_direction << ")" << std::endl;
	}
}

void Robot::SetDirection(DIR direction) {
	m_direction = direction;
}

DIR Robot::GetDirection() {
	return m_direction;
}

void Robot::SetPosX(int const pos) {
	m_posX = pos;
}

int Robot::GetPosX() {
	return m_posX;
}

void Robot::SetPosY(int const pos) {
	m_posY = pos;
}

int Robot::GetPosY() {
	return m_posY;
}

void Robot::SetName(std::string const& name) {
	m_name = name;
}

std::string Robot::GetName() {
	return m_name;
}

std::ostream& operator<<(std::ostream& ost, DIR const dir) {
	if (ost.good()) {
		switch (dir) {
		case DIR::NORTH:
			ost << "NORTH";
			break;
		case DIR::SOUTH:
			ost << "SOUTH";
			break;
		case DIR::EAST:
			ost << "EAST";
			break;
		case DIR::WEST:
			ost << "WEST";
			break;
		default:
			break;
		}
	}
	return ost;
}
