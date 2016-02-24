#include "Def1.h"

Def1::Def1(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void Def1::Initialize() {
}

void Def1::Execute() {
	Robot::driveSubsystem->Drive(-0.75 + (Robot::controlSS->angle * Robot::controlSS->kP), -0.75 - (Robot::controlSS->angle * Robot::controlSS->kP));//1.715 1.1

	SmartDashboard::PutNumber("Left encoder", std::abs(Robot::driveSubsystem->leftEncoder->Get()));
	SmartDashboard::PutNumber("Right encoder", std::abs(Robot::driveSubsystem->rightEncoder->Get()));
	SmartDashboard::PutNumber("Left control", Robot::driveSubsystem->leftControl->Get());
	SmartDashboard::PutNumber("Right control", Robot::driveSubsystem->rightControl->Get());
	SmartDashboard::PutNumber("Last multiplier", Robot::driveSubsystem->lastMult);
	SmartDashboard::PutNumber("Multiplier", Robot::driveSubsystem->multiplier);
}

bool Def1::IsFinished() {
	if(std::abs(Robot::driveSubsystem->leftEncoder->Get()) < 2000){
		return false;
	}

	Robot::driveSubsystem->leftEncoder->Reset();
	Robot::driveSubsystem->rightEncoder->Reset();
	return true;
}

void Def1::End() {
	Robot::driveSubsystem->Stop();
}

void Def1::Interrupted() {
	End();
}
