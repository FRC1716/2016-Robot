#include "Pos1.h"

Pos1::Pos1(): Command() {
	Requires(Robot::controlSS.get());
}

void Pos1::Initialize() {
}

void Pos1::Execute() {
	Robot::controlSS->setPos1();
}

bool Pos1::IsFinished() {
    return false;
}

void Pos1::End() {
}

void Pos1::Interrupted() {
}
