#include "intakeDown.h"

intakeDown::intakeDown(): Command() {
	Requires(Robot::controlSS.get());
}

void intakeDown::Initialize() {
}

void intakeDown::Execute() {
	Robot::controlSS->DownIntake();
}

bool intakeDown::IsFinished() {
    return false;
}

void intakeDown::End() {
	Robot::controlSS->StopIntake();
}

void intakeDown::Interrupted() {
	End();
}
