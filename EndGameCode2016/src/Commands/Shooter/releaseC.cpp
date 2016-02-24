#include "releaseC.h"

releaseC::releaseC(): Command() {
	Requires(Robot::controlSS.get());
}

void releaseC::Initialize() {
}

void releaseC::Execute() {
	Robot::controlSS->runSequence(6);
}

bool releaseC::IsFinished() {
    return false;
}

void releaseC::End() {
}

void releaseC::Interrupted() {
}
