#include "SmallReverse.h"

SmallReverse::SmallReverse() {
	Requires(Robot::controlSS.get());
	Requires(Robot::driveSubsystem.get());
}

void SmallReverse::Initialize() {
}

void SmallReverse::Execute() {
	Robot::driveSubsystem->Drive(0.5 * 1.075, 0.5);//1.715

	SmartDashboard::PutNumber("Left encoder", std::abs(Robot::driveSubsystem->leftEncoder->Get()));
	SmartDashboard::PutNumber("Right encoder", std::abs(Robot::driveSubsystem->rightEncoder->Get()));
	SmartDashboard::PutNumber("Left control", Robot::driveSubsystem->leftControl->Get());
	SmartDashboard::PutNumber("Right control", Robot::driveSubsystem->rightControl->Get());
	SmartDashboard::PutNumber("Last multiplier", Robot::driveSubsystem->lastMult);
	SmartDashboard::PutNumber("Multiplier", Robot::driveSubsystem->multiplier);
}

bool SmallReverse::IsFinished() {
	if(std::abs(Robot::driveSubsystem->leftEncoder->Get()) < 35){
		return false;
	}

	Robot::driveSubsystem->leftEncoder->Reset();
	Robot::driveSubsystem->rightEncoder->Reset();
    return true;
}

void SmallReverse::End() {
	Robot::driveSubsystem->Stop();
}

void SmallReverse::Interrupted() {
	End();
}
