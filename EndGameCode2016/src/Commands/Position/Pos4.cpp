#include "Pos4.h"

Pos4::Pos4(): Command() {
	Requires(Robot::controlSS.get());
}

void Pos4::Initialize() {
}

void Pos4::Execute() {
	Robot::controlSS->setPos4();
}

bool Pos4::IsFinished() {
    return false;
}

void Pos4::End() {
}

void Pos4::Interrupted() {
}
