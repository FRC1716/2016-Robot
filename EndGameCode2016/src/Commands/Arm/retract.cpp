#include "retract.h"

retract::retract(): Command() {
	Requires(Robot::controlSS.get());
}

void retract::Initialize() {
}

void retract::Execute() {
	Robot::controlSS->retract();
}

bool retract::IsFinished() {
    return false;
}

void retract::End() {
	Robot::controlSS->stopLinear();
}

void retract::Interrupted() {
}
