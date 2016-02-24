#include "Def7.h"

Def7::Def7(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void Def7::Initialize() {
}

void Def7::Execute() {
	Robot::driveSubsystem->Stop();
}

bool Def7::IsFinished() {
    return false;
}

void Def7::End() {
}

void Def7::Interrupted() {
}
