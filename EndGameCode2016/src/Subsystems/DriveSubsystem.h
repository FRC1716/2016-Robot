// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVESUBSYSTEM_H
#define DRIVESUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveSubsystem: public Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
public:
	std::shared_ptr<SpeedController> leftControl;
	std::shared_ptr<Encoder> leftEncoder;
	std::shared_ptr<Encoder> rightEncoder;
	std::shared_ptr<SpeedController> rightControl;
	std::shared_ptr<SpeedController> rearLeft;
	std::shared_ptr<SpeedController> rearRight;
	std::shared_ptr<RobotDrive> drive;

	bool changeSensitivity;

	DriveSubsystem();
	void InitDefaultCommand();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
	void Drive(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right);
	void Drive(float left, float right);
	void Stop();
	float CalculateRotations(float distance);
	void sensitivityFalse();
	void sensitivityTrue();

	const int ticksPerRev = 360; //Assumed value. Needs testing
};

#endif
