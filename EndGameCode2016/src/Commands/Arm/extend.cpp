#include "extend.h"

extend::extend(): Command() {
	Requires(Robot::controlSS.get());
}

void extend::Initialize() {
}

void extend::Execute() {
	Robot::controlSS->extend();
}

bool extend::IsFinished() {
    return false;
}

void extend::End() {
	Robot::controlSS->stopLinear();
}

void extend::Interrupted() {
}
