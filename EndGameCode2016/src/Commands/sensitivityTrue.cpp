#include "sensitivityTrue.h"

sensitivityTrue::sensitivityTrue(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void sensitivityTrue::Initialize() {
}

void sensitivityTrue::Execute() {
	Robot::driveSubsystem->sensitivityTrue();
}

bool sensitivityTrue::IsFinished() {
    return false;
}

void sensitivityTrue::End() {
}

void sensitivityTrue::Interrupted() {
}
