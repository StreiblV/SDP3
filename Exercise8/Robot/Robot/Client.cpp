#include "Client.h"


void Client::Test() {

	Robot::SPter Robert{ std::make_shared<Hexapod>("Robert") };
	IRobot::SPter IRobert{ Robert };
	Robot::SPter Harry{ std::make_shared<Wheelbot>("Harry") };
	IRobot::SPter IHarry{ Harry };

	Control ctrl;

	Control::TcmdList cmd;
	cmd.emplace_back(std::make_shared<Forward>(Harry, -300));
	cmd.emplace_back(std::make_shared<TurnLeft>(Harry));
	cmd.emplace_back(std::make_shared<Forward>(Harry, 500));
	cmd.emplace_back(nullptr);


	ctrl.AddCommand(std::make_shared<Forward>(Harry, 300));
	ctrl.AddCommand(std::make_shared<TurnLeft>(Harry));
	ctrl.AddCommand(std::make_shared<TurnRight>(Robert));
	ctrl.AddCommand(std::make_shared<Forward>(Robert, 400));
	ctrl.AddCommand(std::make_shared<MacroMovement>(Harry, cmd));
	ctrl.AddCommand(nullptr);



	ctrl.Start();

	IRobert->Info(std::cout);
	IHarry->Info(std::cout);

	ctrl.Undo(6);

	IRobert->Info(std::cout);
	IHarry->Info(std::cout);

}
