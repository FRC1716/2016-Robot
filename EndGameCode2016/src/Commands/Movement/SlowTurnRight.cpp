#include "SlowTurnRight.h"

SlowTurnRight::SlowTurnRight(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void SlowTurnRight::Initialize() {
}

void SlowTurnRight::Execute() {
	Robot::driveSubsystem->slowRight();
}

bool SlowTurnRight::IsFinished() {
    return false;
}

void SlowTurnRight::End() {
	Robot::driveSubsystem->Stop();
}

void SlowTurnRight::Interrupted() {
	End();
}
