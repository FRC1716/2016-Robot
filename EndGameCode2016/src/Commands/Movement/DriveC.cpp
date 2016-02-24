#include "DriveC.h"

DriveC::DriveC(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void DriveC::Initialize() {
}

void DriveC::Execute() {
	Robot::driveSubsystem->Drive(Robot::oi->getJoystickLeft(), Robot::oi->getJoystickRight());
}

bool DriveC::IsFinished() {
    return false;
}

void DriveC::End() {
	Robot::driveSubsystem->Stop();
}

void DriveC::Interrupted() {
	End();
}
