#include "intakeUp.h"

intakeUp::intakeUp(): Command() {
	Requires(Robot::controlSS.get());
}

void intakeUp::Initialize() {
}

void intakeUp::Execute() {
	Robot::controlSS->UpIntake();
}

bool intakeUp::IsFinished() {
    return false;
}

void intakeUp::End() {
	Robot::controlSS->StopIntake();
}

void intakeUp::Interrupted() {
	End();
}
