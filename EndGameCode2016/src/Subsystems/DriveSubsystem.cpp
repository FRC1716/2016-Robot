#include "DriveSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/Movement/DriveC.h"

DriveSubsystem::DriveSubsystem() : Subsystem("DriveSubsystem") {
    leftControl = RobotMap::driveSubsystemLeftControl;
    leftEncoder = RobotMap::driveSubsystemLeftEncoder;
    rightEncoder = RobotMap::driveSubsystemRightEncoder;
    rightControl = RobotMap::driveSubsystemRightControl;
    rearLeft = RobotMap::driveSubsystemRearLeft;
    rearRight = RobotMap::driveSubsystemRearRight;
    drive = RobotMap::driveSubsystemDrive;

    dist = 0;
    lastMult = 1.715;
    multiplier = 1.715;

    changeSensitivity = false;
}

void DriveSubsystem::InitDefaultCommand() {
     SetDefaultCommand(new DriveC());
}



void DriveSubsystem::Drive(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right){
	leftControl->Set(left->GetY());
	rightControl->Set(-right->GetY());

	if (changeSensitivity == false){
		drive->TankDrive(left->GetY(), right->GetY());
	}else if (changeSensitivity == true){
		float leftSquare = left->GetY() * left->GetY();
		float rightSquare = right->GetY() * right->GetY();

		if (left->GetY() < 0){
			leftSquare = -leftSquare;
		}
		if (right->GetY() < 0){
			rightSquare = -rightSquare;
		}

		SmartDashboard::PutNumber("Squared left:", leftSquare);
		SmartDashboard::PutNumber("Squared right:", rightSquare);

		drive->TankDrive(leftSquare, rightSquare);
	}
}
void DriveSubsystem::Drive(float left, float right){
	//leftControl->Set(left);
	//rightControl->Set(-right);
	drive->TankDrive(left, right);
}
void DriveSubsystem::Stop(){
	//leftControl->Set(0);
	//rightControl->Set(0);
	drive->StopMotor();
}

double DriveSubsystem::CalculateRotations(float distance){
	return distance/(4*M_PI);
}

float DriveSubsystem::CalculateDistance(int ticks){
	return (ticks/ticksPerRev)*(4*M_PI);
}

void DriveSubsystem::sensitivityFalse(){
	changeSensitivity = false;
}
void DriveSubsystem::sensitivityTrue(){
	changeSensitivity = true;
}

void DriveSubsystem::driveStraight(std::shared_ptr<Joystick> left, std::shared_ptr<Joystick> right){
	double joyLeft = left->GetY();
	double joyRight = right->GetY();

	multiplier = ((joyRight / joyLeft) / (std::abs(rightEncoder->Get()) / std::abs(leftEncoder->Get())));

	if (lastMult ==  1000000.0){
		leftControl->Set(joyLeft / multiplier);
		lastMult = multiplier;
	}else{
		multiplier = (multiplier + lastMult) / 2;

		lastMult = multiplier;

		leftControl->Set(joyLeft / multiplier);
	}

	rightControl->Set(joyRight);

	drive->TankDrive(leftControl->Get(), rightControl->Get());
}

void DriveSubsystem::driveStraight(double left, double right){
	rightControl->Set(-right);
	leftControl->Set(left);

	if (rightEncoder->Get() != 0.0 && leftEncoder->Get() != 0.0){
		multiplier = ((right / left) / ((double) std::abs(rightEncoder->Get()) / (double) std::abs(leftEncoder->Get())));


		if (lastMult == 1.715){
			leftControl->Set(left * multiplier);

			lastMult = multiplier;
		}else{
			multiplier = (multiplier + lastMult) / 2.0;

			lastMult = multiplier;

			leftControl->Set(left * multiplier);
		}

	}

	drive->TankDrive(leftControl->Get(), rightControl->Get(), false);
}

void DriveSubsystem::slowLeft(){

}

void DriveSubsystem::slowRight(){

}
