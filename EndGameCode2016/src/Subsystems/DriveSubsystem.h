#ifndef DRIVESUBSYSTEM_H
#define DRIVESUBSYSTEM_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveSubsystem: public Subsystem {
private:
public:
	std::shared_ptr<SpeedController> leftControl;
	std::shared_ptr<Encoder> leftEncoder;
	std::shared_ptr<Encoder> rightEncoder;
	std::shared_ptr<SpeedController> rightControl;
	std::shared_ptr<SpeedController> rearLeft;
	std::shared_ptr<SpeedController> rearRight;
	std::shared_ptr<RobotDrive> drive;

	int dist;

	double lastMult;
	double multiplier;

	bool changeSensitivity;

	DriveSubsystem();
	void InitDefaultCommand();

	void Drive(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right);
	void Drive(float left, float right);
	void Stop();
	double CalculateRotations(float distance);
	float CalculateDistance(int ticks);
	void sensitivityFalse();
	void sensitivityTrue();
	void driveStraight(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right);
	void driveStraight(double left, double right);
	void slowLeft();
	void slowRight();

	const int ticksPerRev = 360; //Assumed value. Needs testing
};

#endif
