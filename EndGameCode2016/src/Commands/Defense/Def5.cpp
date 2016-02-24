#include "Def5.h"

Def5::Def5(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void Def5::Initialize() {
}

void Def5::Execute() {
}

bool Def5::IsFinished() {
    return false;
}

void Def5::End() {
}

void Def5::Interrupted() {
}
