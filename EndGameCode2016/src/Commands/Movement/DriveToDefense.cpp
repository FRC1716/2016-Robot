#include "DriveToDefense.h"

DriveToDefense::DriveToDefense(): Command() {
	Requires(Robot::driveSubsystem.get());

	distance = Robot::driveSubsystem->CalculateRotations(85.61);
}

void DriveToDefense::Initialize() {
}

void DriveToDefense::Execute() {
	Robot::driveSubsystem->Drive(-0.5 + (Robot::controlSS->angle * Robot::controlSS->kP), -0.5 - (Robot::controlSS->angle * Robot::controlSS->kP));//1.715 1.1
}

bool DriveToDefense::IsFinished() {
	if(std::abs(Robot::driveSubsystem->leftEncoder->Get()) < 1000){
		return false;
	}

	Robot::driveSubsystem->leftEncoder->Reset();
	Robot::driveSubsystem->rightEncoder->Reset();
    return true;
}

void DriveToDefense::End() {
	Robot::driveSubsystem->Stop();
}

void DriveToDefense::Interrupted() {
	End();
}
