
#include <iostream>

#include <memory>

#include "Control.h"
#include "Forward.h"
#include "TurnLeft.h"
#include "TurnRight.h"
#include "MacroMovement.h"


#include "Robot.h"
#include "Wheelbot.h"
#include "Hexapod.h"

using namespace std;
int main() {
	Robot::SPter Robert{make_shared<Hexapod>( "Robert") };
	Robot::SPter Harry{ make_shared<Wheelbot>("Harry") };
	Control ctrl;
	
	
	
	TurnLeft Left(Harry);

	ctrl.AddCommand(make_shared<Forward>(Harry, 300));
	ctrl.AddCommand(make_shared<TurnLeft>(Harry));
	ctrl.AddCommand(make_shared<TurnRight>(Robert));
	ctrl.AddCommand(make_shared<Forward>(Robert, 400));
	ctrl.Start();

	Robert->Info(cout);
	Harry->Info(cout);

	ctrl.Undo(4);

	Robert->Info(cout);
	Harry->Info(cout);




}