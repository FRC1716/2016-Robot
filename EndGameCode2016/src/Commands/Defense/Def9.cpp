#include "Def9.h"

Def9::Def9(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void Def9::Initialize() {
}

void Def9::Execute() {
	Robot::driveSubsystem->Stop();
}

bool Def9::IsFinished() {
    return false;
}

void Def9::End() {
}

void Def9::Interrupted() {
}
