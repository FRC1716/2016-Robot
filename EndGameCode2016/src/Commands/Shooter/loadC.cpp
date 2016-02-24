#include "loadC.h"

loadC::loadC(): Command() {
	Requires(Robot::controlSS.get());
}

void loadC::Initialize() {
}

void loadC::Execute() {
	Robot::controlSS->runSequence(6);
}

bool loadC::IsFinished() {
    return false;
}

void loadC::End() {
}

void loadC::Interrupted() {
}
