#include "Def4.h"

Def4::Def4(): Command() {
	Requires(Robot::driveSubsystem.get());
}

void Def4::Initialize() {
}

void Def4::Execute() {
	Robot::driveSubsystem->Drive(-0.5 + (Robot::controlSS->angle * Robot::controlSS->kP), -0.5 - (Robot::controlSS->angle * Robot::controlSS->kP));//1.715 1.1

	SmartDashboard::PutNumber("Left encoder", std::abs(Robot::driveSubsystem->leftEncoder->Get()));
	SmartDashboard::PutNumber("Right encoder", std::abs(Robot::driveSubsystem->rightEncoder->Get()));
	SmartDashboard::PutNumber("Left control", Robot::driveSubsystem->leftControl->Get());
	SmartDashboard::PutNumber("Right control", Robot::driveSubsystem->rightControl->Get());
	SmartDashboard::PutNumber("Last multiplier", Robot::driveSubsystem->lastMult);
	SmartDashboard::PutNumber("Multiplier", Robot::driveSubsystem->multiplier);
}

bool Def4::IsFinished() {
	if(std::abs(Robot::driveSubsystem->leftEncoder->Get()) < 2000){
		return false;
	}

	Robot::driveSubsystem->leftEncoder->Reset();
	Robot::driveSubsystem->rightEncoder->Reset();
	return true;
}

void Def4::End() {
	Robot::driveSubsystem->Stop();
}

void Def4::Interrupted() {
	End();
}
