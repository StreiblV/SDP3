#include "ICommand.h"

ICommand::ICommand(std::shared_ptr<Robot> robot) {
	if (robot == nullptr) {
		throw std::exception("Nullpointer in Constructor!");
	}
	m_robot = robot;
}
