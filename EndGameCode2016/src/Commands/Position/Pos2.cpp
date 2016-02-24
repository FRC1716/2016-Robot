#include "Pos2.h"

Pos2::Pos2(): Command() {
	Requires(Robot::controlSS.get());
}

void Pos2::Initialize() {
}

void Pos2::Execute() {
	Robot::controlSS->setPos2();
}

bool Pos2::IsFinished() {
    return false;
}

void Pos2::End() {
}

void Pos2::Interrupted() {
}
