// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robot builder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.

#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/DriveC.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveSubsystem::DriveSubsystem() : Subsystem("DriveSubsystem") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    leftControl = RobotMap::driveSubsystemLeftControl;
    leftEncoder = RobotMap::driveSubsystemLeftEncoder;
    rightEncoder = RobotMap::driveSubsystemRightEncoder;
    rightControl = RobotMap::driveSubsystemRightControl;
    rearLeft = RobotMap::driveSubsystemRearLeft;
    rearRight = RobotMap::driveSubsystemRearRight;
    drive = RobotMap::driveSubsystemDrive;
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void DriveSubsystem::InitDefaultCommand() {
    // Set the default command for a subsystem here.
     SetDefaultCommand(new DriveC());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.
void DriveSubsystem::Drive(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right){
	leftControl->Set(left->GetY());
	rightControl->Set(-right->GetY());
	drive->TankDrive(left->GetY(), right->GetY());
}

void DriveSubsystem::Drive(float left, float right){
	leftControl->Set(left);
	rightControl->Set(-right);
	drive->TankDrive(left, right);
}

void DriveSubsystem::Stop(){
	leftControl->Set(0);
	rightControl->Set(0);
	drive->StopMotor();
}
