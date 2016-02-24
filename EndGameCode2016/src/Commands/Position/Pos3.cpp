#include "Pos3.h"

Pos3::Pos3(): Command() {
	Requires(Robot::controlSS.get());
}

void Pos3::Initialize() {
}

void Pos3::Execute() {
	Robot::controlSS->setPos3();
}

bool Pos3::IsFinished() {
    return false;
}

void Pos3::End() {
}

void Pos3::Interrupted() {
}
