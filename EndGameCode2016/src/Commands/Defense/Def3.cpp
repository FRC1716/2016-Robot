#include "Def3.h"

Def3::Def3(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void Def3::Initialize() {
}

void Def3::Execute() {
}

bool Def3::IsFinished() {
    return false;
}

void Def3::End() {
}

void Def3::Interrupted() {
}
