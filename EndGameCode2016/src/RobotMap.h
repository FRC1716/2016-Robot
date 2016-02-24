#ifndef ROBOTMAP_H
#define ROBOTMAP_H
#include "WPILib.h"

class RobotMap {
public:
	static std::shared_ptr<SpeedController> controlSSarmAngle1;
	static std::shared_ptr<SpeedController> controlSSarmAngle2;
	static std::shared_ptr<SpeedController> controlSSarmExtend1;
	static std::shared_ptr<AnalogGyro> controlSSgyro;
	static std::shared_ptr<SpeedController> driveSubsystemLeftControl;
	static std::shared_ptr<Encoder> driveSubsystemLeftEncoder;
	static std::shared_ptr<Encoder> driveSubsystemRightEncoder;
	static std::shared_ptr<SpeedController> driveSubsystemRightControl;
	static std::shared_ptr<SpeedController> driveSubsystemRearLeft;
	static std::shared_ptr<SpeedController> driveSubsystemRearRight;
	static std::shared_ptr<RobotDrive> driveSubsystemDrive;
	static std::shared_ptr<SpeedController> windowMotor;
	static std::shared_ptr<DigitalInput> controlSSfrontLS;
	static std::shared_ptr<DigitalInput> controlSSbackLS;
	static std::shared_ptr<DigitalInput> controlSSsideLS;
	static std::shared_ptr<Solenoid> controlSSsolenoid0;
	static std::shared_ptr<Solenoid> controlSSsolenoid1;
	static std::shared_ptr<Solenoid> controlSSsolenoid2;
	static std::shared_ptr<Solenoid> controlSSsolenoid3;
	static std::shared_ptr<AnalogInput> controlSSpressureGauge;
	static std::shared_ptr<SpeedController> controlSSintake;

	static void init();
};
#endif
