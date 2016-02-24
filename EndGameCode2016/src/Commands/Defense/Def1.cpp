// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Def1.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Def1::Def1(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveSubsystem.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Def1::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Def1::Execute() {
	Robot::driveSubsystem->Drive(-0.75 + (Robot::controlSS->angle * Robot::controlSS->kP), -0.75 - (Robot::controlSS->angle * Robot::controlSS->kP));//1.715 1.1

	SmartDashboard::PutNumber("Left encoder", std::abs(Robot::driveSubsystem->leftEncoder->Get()));
	SmartDashboard::PutNumber("Right encoder", std::abs(Robot::driveSubsystem->rightEncoder->Get()));
	SmartDashboard::PutNumber("Left control", Robot::driveSubsystem->leftControl->Get());
	SmartDashboard::PutNumber("Right control", Robot::driveSubsystem->rightControl->Get());
	SmartDashboard::PutNumber("Last multiplier", Robot::driveSubsystem->lastMult);
	SmartDashboard::PutNumber("Multiplier", Robot::driveSubsystem->multiplier);
}

// Make this return true when this Command no longer needs to run execute()
bool Def1::IsFinished() {
	if(std::abs(Robot::driveSubsystem->leftEncoder->Get()) < 2000){
		return false;
	}

	Robot::driveSubsystem->leftEncoder->Reset();
	Robot::driveSubsystem->rightEncoder->Reset();
	return true;
}

// Called once after isFinished returns true
void Def1::End() {
	Robot::driveSubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Def1::Interrupted() {
	End();
}