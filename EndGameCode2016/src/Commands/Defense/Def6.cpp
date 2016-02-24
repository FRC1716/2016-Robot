#include "Def6.h"

Def6::Def6(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void Def6::Initialize() {
}

void Def6::Execute() {
	Robot::driveSubsystem->Stop();
}

bool Def6::IsFinished() {
    return false;
}

void Def6::End() {
}

void Def6::Interrupted() {
}
