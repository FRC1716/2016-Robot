#include "sensitivityFalse.h"

sensitivityFalse::sensitivityFalse(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void sensitivityFalse::Initialize() {
}

void sensitivityFalse::Execute() {
	Robot::driveSubsystem->sensitivityFalse();
}

bool sensitivityFalse::IsFinished() {
    return false;
}

void sensitivityFalse::End() {
}

void sensitivityFalse::Interrupted() {
}
