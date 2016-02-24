#ifndef CONTROLSS_H
#define CONTROLSS_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

class ControlSS: public Subsystem {
private:
public:
	ControlSS();
	void InitDefaultCommand();

	//create integer variables
	int posNum;
	int defNum;
	int afterNum;
	int windowNum;
	int loadingPressure;
	int firingPressure;
	//create double variables
	double beginTime;
	double shooterPSI;
	double armPSI;
	//create float variables
	float angle;
	static constexpr float kP = 0.03f;
	//create boolean variables
	bool latchState;//0 = latchSol[0] & 1 = latchSol[1]
	bool loaderState;//0 = loaderSol[0] & 1 = loaderSol[1]
	bool loaded;
	bool canBreach;
	bool canReverse;
	bool locked;
	//create timer variables
	Timer* gameTimer;
	//create all other objects
	std::shared_ptr<SpeedController> armAngle1;
	std::shared_ptr<SpeedController> armAngle2;
	std::shared_ptr<SpeedController> armExtend1;
	std::shared_ptr<RobotDrive> robotDrive;
	std::shared_ptr<AnalogGyro> gyro;
	std::shared_ptr<Solenoid> latchSol[2];
	std::shared_ptr<Solenoid> loaderSol[2];
	std::shared_ptr<DigitalInput> frontLS;
	std::shared_ptr<DigitalInput> backLS;
	std::shared_ptr<DigitalInput> sideLS;
	std::shared_ptr<AnalogInput> pressureGauge;
	std::shared_ptr<SpeedController> intakeMotor;
	//create SC objects
	SendableChooser* posSC;
	SendableChooser* defSC;
	SendableChooser* senSC;
	SendableChooser* afterSC;
	SendableChooser* beforeSC;
	//create methods to control drive
	void drive(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right);
	void stop();
	//create methods to update variable for pressure gauges
	void updateShooter();
	void updateArm();
	//create methods to control window motor
	void windowForward();
	void windowReverse();
	void windowStop();
	//create methods to set position number
	void setPos1();
	void setPos2();
	void setPos3();
	void setPos4();
	void setPos5();
	//create arm methods
	void out();
	void in();
	void extend();
	void retract();
	void stopLinear();
	void stopRotate();
	//create gyro methods
	void updateGyro();
	//create utility methods
	void wait(double seconds);
	void startTimer();
	double elapsedTime();
	//create shooter methods
	void toggle(int toggleNum);
	void setSols(int  cylinder, int state);
	void allSolsLow();
	void updateSols(int cylinder);
	void waitForPSI(int x);
	void runSequence(int x);
	void reset();
	void unlockShooter();
	void lockShooter();
	//create methods for intake
	void UpIntake();
	void DownIntake();
	void StopIntake();
};

#endif
