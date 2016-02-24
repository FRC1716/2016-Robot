#include "DriveReverse.h"

DriveReverse::DriveReverse() {
	Requires(Robot::controlSS.get());
	Requires(Robot::driveSubsystem.get());
}

void DriveReverse::Initialize() {
}

void DriveReverse::Execute() {
	Robot::driveSubsystem->Drive(0.5 * 1.075, 0.5);//1.715

	SmartDashboard::PutNumber("Left encoder", std::abs(Robot::driveSubsystem->leftEncoder->Get()));
	SmartDashboard::PutNumber("Right encoder", std::abs(Robot::driveSubsystem->rightEncoder->Get()));
	SmartDashboard::PutNumber("Left control", Robot::driveSubsystem->leftControl->Get());
	SmartDashboard::PutNumber("Right control", Robot::driveSubsystem->rightControl->Get());
	SmartDashboard::PutNumber("Last multiplier", Robot::driveSubsystem->lastMult);
	SmartDashboard::PutNumber("Multiplier", Robot::driveSubsystem->multiplier);
}

bool DriveReverse::IsFinished() {
	if(std::abs(Robot::driveSubsystem->leftEncoder->Get()) < 3150){
		return false;
	}

	Robot::driveSubsystem->leftEncoder->Reset();
	Robot::driveSubsystem->rightEncoder->Reset();
    return true;
}

void DriveReverse::End() {
	Robot::driveSubsystem->Stop();
}

void DriveReverse::Interrupted() {
	End();
}
