#include "rotateIn.h"

rotateIn::rotateIn(): Command() {
	Requires(Robot::controlSS.get());
}

void rotateIn::Initialize() {
}

void rotateIn::Execute() {
	Robot::controlSS->in();
}

bool rotateIn::IsFinished() {
    return false;
}

void rotateIn::End() {
	Robot::controlSS->stopRotate();
}

void rotateIn::Interrupted() {
}
