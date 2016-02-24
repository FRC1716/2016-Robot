#include "Pos5.h"

Pos5::Pos5(): Command() {
	Requires(Robot::controlSS.get());
}

void Pos5::Initialize() {
}

void Pos5::Execute() {
	Robot::controlSS->setPos5();
}

bool Pos5::IsFinished() {
    return false;
}

void Pos5::End() {
}

void Pos5::Interrupted() {
}
