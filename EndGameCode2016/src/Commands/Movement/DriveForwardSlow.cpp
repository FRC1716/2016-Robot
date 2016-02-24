#include "DriveForwardSlow.h"

DriveForwardSlow::DriveForwardSlow() {
	Requires(Robot::controlSS.get());
	Requires(Robot::driveSubsystem.get());
}

void DriveForwardSlow::Initialize() {
}

void DriveForwardSlow::Execute() {
	Robot::driveSubsystem->Drive(-0.3 + (Robot::controlSS->angle * Robot::controlSS->kP), -0.3 - (Robot::controlSS->angle * Robot::controlSS->kP));//1.715 1.1

	SmartDashboard::PutNumber("Left encoder", std::abs(Robot::driveSubsystem->leftEncoder->Get()));
	SmartDashboard::PutNumber("Right encoder", std::abs(Robot::driveSubsystem->rightEncoder->Get()));
	SmartDashboard::PutNumber("Left control", Robot::driveSubsystem->leftControl->Get());
	SmartDashboard::PutNumber("Right control", Robot::driveSubsystem->rightControl->Get());
	SmartDashboard::PutNumber("Last multiplier", Robot::driveSubsystem->lastMult);
	SmartDashboard::PutNumber("Multiplier", Robot::driveSubsystem->multiplier);
		//Robot::driveSubsystem->driveStraight(-0.5, -0.5);
}

bool DriveForwardSlow::IsFinished() {
	if(std::abs(Robot::driveSubsystem->leftEncoder->Get()) < 150){
		return false;
	}

	Robot::driveSubsystem->leftEncoder->Reset();
	Robot::driveSubsystem->rightEncoder->Reset();
    return true;
}

void DriveForwardSlow::End() {
	Robot::driveSubsystem->Stop();
}

void DriveForwardSlow::Interrupted() {
	End();
}
