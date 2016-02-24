#include "Def2.h"

Def2::Def2(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void Def2::Initialize() {
}

void Def2::Execute() {
	Robot::driveSubsystem->Stop();
}

bool Def2::IsFinished() {
    return false;
}

void Def2::End() {
}

void Def2::Interrupted() {
}
