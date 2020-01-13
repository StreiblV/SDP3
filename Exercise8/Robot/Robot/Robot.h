/* ______________________________________________________________________
| Workfile : Robot.h
| Description : [ HEADER ]
| Name : Viktoria Streibl		PKZ : S1810306013
| Date : 13.01.2020
| Remarks : -
| Revision : 0
| _______________________________________________________________________ */

#ifndef ROBOT_H
#define ROBOT_H
#include <ostream>

enum class DIR {
	NORTH,
	SOUTH,
	EAST,
	WEST
};
std::ostream& operator<<(std::ostream& ost, DIR const dir);



#include "IRobot.h"
class Robot : public IRobot {
public:
	Robot() : m_posX{ 0 }, m_posY{ 0 }, m_direction{ DIR::NORTH }, m_name{ "" } {}
	Robot(std::string const& name) : m_posX{ 0 }, m_posY{ 0 }, m_direction{ DIR::NORTH }, m_name{ name } {}

	virtual void Info(std::ostream& ost) override;

	void SetDirection(DIR direction);
	DIR GetDirection();

	void SetPosX(int const pos);
	int GetPosX();

	void SetPosY(int const pos);
	int GetPosY();

	void SetName(std::string const& name);
	std::string GetName();

	using SPter = std::shared_ptr<Robot>;

private:
	std::string m_name;

	int m_posX;
	int m_posY;
	DIR m_direction;
};

#endif//!ROBOT_H

