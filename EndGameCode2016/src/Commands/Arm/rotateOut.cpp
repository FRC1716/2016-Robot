#include "rotateOut.h"

rotateOut::rotateOut(): Command() {
	Requires(Robot::controlSS.get());
}

void rotateOut::Initialize() {
}

void rotateOut::Execute() {
	Robot::controlSS->out();
}

bool rotateOut::IsFinished() {
    return false;
}

void rotateOut::End() {
	Robot::controlSS->out();
}

void rotateOut::Interrupted() {
}
