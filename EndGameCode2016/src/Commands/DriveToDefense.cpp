// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robot builder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "DriveToDefense.h"
#include "../Subsystems/DriveSubsystem.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

DriveToDefense::DriveToDefense(): Command() {
        // Use requires() here to declare subsystem dependencies
    // eg. requires(chassis);
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::driveSubsystem.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	distance = Robot::driveSubsystem->CalculateRotations(85.61);
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void DriveToDefense::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveToDefense::Execute() {
	//Reset encoders
	Robot::driveSubsystem->leftEncoder->Reset();
	Robot::driveSubsystem->rightEncoder->Reset();

	while ((Robot::driveSubsystem->leftEncoder->Get() < (Robot::driveSubsystem->ticksPerRev * distance)) && (Robot::driveSubsystem->rightEncoder->Get() < (Robot::driveSubsystem->ticksPerRev * distance)))
		Robot::driveSubsystem->Drive(0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveToDefense::IsFinished() {
    return (Robot::driveSubsystem->leftEncoder->Get() < (Robot::driveSubsystem->ticksPerRev * distance)) && (Robot::driveSubsystem->rightEncoder->Get() < (Robot::driveSubsystem->ticksPerRev * distance));
}

// Called once after isFinished returns true
void DriveToDefense::End() {
	Robot::driveSubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveToDefense::Interrupted() {
	End();
}
