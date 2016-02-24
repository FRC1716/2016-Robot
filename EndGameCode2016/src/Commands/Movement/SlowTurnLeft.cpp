#include "SlowTurnLeft.h"

SlowTurnLeft::SlowTurnLeft(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void SlowTurnLeft::Initialize() {
}

void SlowTurnLeft::Execute() {
	Robot::driveSubsystem->slowLeft();
}

bool SlowTurnLeft::IsFinished() {
    return false;
}

void SlowTurnLeft::End() {
	Robot::driveSubsystem->Stop();
}

void SlowTurnLeft::Interrupted() {
	End();
}
