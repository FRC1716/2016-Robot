// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Robot.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
std::shared_ptr<ControlSS> Robot::controlSS;
std::shared_ptr<DriveSubsystem> Robot::driveSubsystem;
std::unique_ptr<OI> Robot::oi;
//std::shared_ptr<SendableChooser> Robot::posSC;
//std::shared_ptr<SendableChooser> Robot::defSC;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION

void Robot::RobotInit() {
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    controlSS.reset(new ControlSS());
    driveSubsystem.reset(new DriveSubsystem());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi.reset(new OI());

	//setting up position SC
	posSC = new SendableChooser();
	//adding all options to choose to posSC
	posSC->AddDefault("Left 1 (Default)", new Pos1());
	posSC->AddObject("Left/Middle 2", new Pos2());
	posSC->AddObject("Middle 3", new Pos3());
	posSC->AddObject("Right/Middle 4", new Pos4());
	posSC->AddObject("Right 5", new Pos5());

	//make options viewable on dash
	SmartDashboard::PutData("Positions", posSC);

	//setting up defense SC
	defSC = new SendableChooser();
	//adding all options to choose to defSC
	defSC->AddDefault("Low bar 1 (Default)", new Def1());
	defSC->AddObject("Portcullis 2", new Def2());
	defSC->AddObject("Cheval de Frise 3", new Def3());
	defSC->AddObject("Moat 4", new Def4());
	defSC->AddObject("Ramparts 5", new Def5());
	defSC->AddObject("Drawbridge 6", new Def6());
	defSC->AddObject("Sally Port 7", new Def7());
	defSC->AddObject("Rock Wall 8", new Def8());
	defSC->AddObject("Rough Terrain 9", new Def9());
	//make defSC viewable on dash
	SmartDashboard::PutData("Defense", defSC);

	//setting up sensitivity SC
	senSC = new SendableChooser();
	//adding all options to choose to senSC
	senSC->AddDefault("Normal sensitivity", new sensitivityFalse());
	senSC->AddObject("Lower sensitivity", new sensitivityTrue());
	//make senSC viewable on dash
	SmartDashboard::PutData("Sensitivity", senSC);

	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand.reset(new AutonomousCommand());
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
  }

/**
 * This function is called when the disabled button is hit.
 * You can use it to reset subsystems before shutting down.
 */
void Robot::DisabledInit(){

}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();

	Robot::controlSS->gameTimer->Reset();

	//Robot::controlSS->updateShooter();
	SmartDashboard::PutNumber("Shooter PSI", Robot::controlSS->shooterPSI);
	SmartDashboard::PutBoolean("Can use shooter?", Robot::controlSS->shooterUse);
	//Robot::controlSS->updateArm();
	SmartDashboard::PutNumber("Arm PSI", Robot::controlSS->armPSI);
	SmartDashboard::PutBoolean("Can use arm?", Robot::controlSS->armUse);
}

void Robot::AutonomousInit() {
	//create Command objects to get options selected by SCs
	Command* temp = (Command*) posSC->GetSelected();
	Command* temp2 = (Command*) defSC->GetSelected();
	Command* temp3 = (Command*) senSC->GetSelected();
	//run both commands that were chosen
	temp->Run();
	temp2->Run();
	temp3->Run();
	//show on dash what numbers were chosen
	SmartDashboard::PutNumber("Position selected:", Robot::controlSS->posNum);
	SmartDashboard::PutNumber("Defense selected:", Robot::controlSS->defNum);
	SmartDashboard::PutBoolean("Sensitivity:", Robot::driveSubsystem->changeSensitivity);

	Robot::controlSS->updateGyro();
	SmartDashboard::PutNumber("Gyro angle: ", Robot::controlSS->angle);
	SmartDashboard::PutNumber("DB/String 0", Robot::controlSS->angle);

	/*Robot::controlSS->updateShooter();
	SmartDashboard::PutNumber("Shooter PSI", Robot::controlSS->shooterPSI);
	SmartDashboard::PutBoolean("Can use shooter?", Robot::controlSS->shooterUse);
	Robot::controlSS->updateArm();
	SmartDashboard::PutNumber("Arm PSI", Robot::controlSS->armPSI);
	SmartDashboard::PutBoolean("Can use arm?", Robot::controlSS->armUse);*/

	SmartDashboard::PutNumber("Left Joystick:", Robot::oi->getJoystickLeft()->GetY());
	SmartDashboard::PutNumber("Right Joystick:", Robot::oi->getJoystickRight()->GetY());

	if (autonomousCommand.get() != nullptr){
		Robot::controlSS->gameTimer->Reset();
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();

	//create Command objects to get options selected by SCs
	Command* temp = (Command*) posSC->GetSelected();
	Command* temp2 = (Command*) defSC->GetSelected();
	Command* temp3 = (Command*) senSC->GetSelected();
	//run both commands that were chosen
	temp->Run();
	temp2->Run();
	temp3->Run();
	//show on dash what numbers were chosen
	SmartDashboard::PutNumber("Position selected:", Robot::controlSS->posNum);
	SmartDashboard::PutNumber("Defense selected:", Robot::controlSS->defNum);
	SmartDashboard::PutBoolean("Sensitivity:", Robot::driveSubsystem->changeSensitivity);

	Robot::controlSS->updateGyro();
	SmartDashboard::PutNumber("Gyro angle: ", Robot::controlSS->angle);
	SmartDashboard::PutNumber("DB/String 0", Robot::controlSS->angle);

	SmartDashboard::PutNumber("Auto Time", Robot::controlSS->gameTimer->Get());

	SmartDashboard::PutData("Positions", posSC);
	SmartDashboard::PutData("Defense", defSC);

	/*
	Robot::controlSS->updateShooter();
	SmartDashboard::PutNumber("Shooter PSI", Robot::controlSS->shooterPSI);
	SmartDashboard::PutBoolean("Can use shooter?", Robot::controlSS->shooterUse);
	Robot::controlSS->updateArm();
	SmartDashboard::PutNumber("Arm PSI", Robot::controlSS->armPSI);
	SmartDashboard::PutBoolean("Can use arm?", Robot::controlSS->armUse);*/

	/*
	SmartDashboard::PutBoolean("Loader 1: ", Robot::controlSS->loaderSol[0]->Get());
	SmartDashboard::PutBoolean("Loader 2: ", Robot::controlSS->loaderSol[1]->Get());
	SmartDashboard::PutBoolean("Latch 1: ", Robot::controlSS->latchSol[0]->Get());
	SmartDashboard::PutBoolean("Latch 2: ", Robot::controlSS->latchSol[1]->Get());
	SmartDashboard::PutBoolean("Front Limit Switch: ", Robot::controlSS->frontLS->Get());
	SmartDashboard::PutBoolean("Side Limit Switch: ", Robot::controlSS->sideLS->Get());
	SmartDashboard::PutBoolean("Back Limit Switch: ", Robot::controlSS->backLS->Get());
	SmartDashboard::PutBoolean("Loaded: ", Robot::controlSS->loaded);
	*/

	SmartDashboard::PutNumber("Left Joystick:", Robot::oi->getJoystickLeft()->GetY());
	SmartDashboard::PutNumber("Right Joystick:", Robot::oi->getJoystickRight()->GetY());
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	Command* temp3 = (Command*) senSC->GetSelected();
	temp3->Run();
	SmartDashboard::PutBoolean("Sensitivity:", Robot::driveSubsystem->changeSensitivity);

	//Robot::controlSS->updateShooter();
	/*
	SmartDashboard::PutNumber("Shooter PSI", Robot::controlSS->shooterPSI);
	SmartDashboard::PutBoolean("Can use shooter?", Robot::controlSS->shooterUse);
	//Robot::controlSS->updateArm();
	SmartDashboard::PutNumber("Arm PSI", Robot::controlSS->armPSI);
	SmartDashboard::PutBoolean("Can use arm?", Robot::controlSS->armUse);
	*/

	Robot::controlSS->updateGyro();
	SmartDashboard::PutNumber("Gyro angle: ", Robot::controlSS->angle);
	SmartDashboard::PutNumber("DB/String 0", Robot::controlSS->angle);

	SmartDashboard::PutNumber("Left Joystick:", Robot::oi->getJoystickLeft()->GetY());
	SmartDashboard::PutNumber("Right Joystick:", Robot::oi->getJoystickRight()->GetY());

	if (autonomousCommand.get() != nullptr){
		Robot::controlSS->gameTimer->Reset();
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();

	Command* temp3 = (Command*) senSC->GetSelected();
	temp3->Run();
	SmartDashboard::PutBoolean("Sensitivity:", Robot::driveSubsystem->changeSensitivity);

	SmartDashboard::PutNumber("Teleop Time", Robot::controlSS->gameTimer->Get());

	SmartDashboard::PutData("Positions", posSC);
	SmartDashboard::PutData("Defense", defSC);

	Robot::controlSS->updateGyro();
	SmartDashboard::PutNumber("Gyro angle: ", Robot::controlSS->angle);
	SmartDashboard::PutNumber("DB/String 0", Robot::controlSS->angle);

	//Robot::controlSS->updateShooter();
	/*
	SmartDashboard::PutNumber("Shooter PSI", Robot::controlSS->shooterPSI);
	SmartDashboard::PutBoolean("Can use shooter?", Robot::controlSS->shooterUse);
	//Robot::controlSS->updateArm();
	SmartDashboard::PutNumber("Arm PSI", Robot::controlSS->armPSI);
	SmartDashboard::PutBoolean("Can use arm?", Robot::controlSS->armUse);
	*/

	/*
	SmartDashboard::PutBoolean("Loader 1: ", Robot::controlSS->loaderSol[0]->Get());
	SmartDashboard::PutBoolean("Loader 2: ", Robot::controlSS->loaderSol[1]->Get());
	SmartDashboard::PutBoolean("Latch 1: ", Robot::controlSS->latchSol[0]->Get());
	SmartDashboard::PutBoolean("Latch 2: ", Robot::controlSS->latchSol[1]->Get());
	SmartDashboard::PutBoolean("Front Limit Switch: ", Robot::controlSS->frontLS->Get());
	SmartDashboard::PutBoolean("Side Limit Switch: ", Robot::controlSS->sideLS->Get());
	SmartDashboard::PutBoolean("Back Limit Switch: ", Robot::controlSS->backLS->Get());
	SmartDashboard::PutBoolean("Loaded: ", Robot::controlSS->loaded);
*/
	SmartDashboard::PutNumber("Left Joystick:", Robot::oi->getJoystickLeft()->GetY());
	SmartDashboard::PutNumber("Right Joystick:", Robot::oi->getJoystickRight()->GetY());
}

void Robot::TestPeriodic() {
	lw->Run();

	Robot::controlSS->updateGyro();
	SmartDashboard::PutNumber("Gyro angle: ", Robot::controlSS->angle);
	SmartDashboard::PutNumber("DB/String 0", Robot::controlSS->angle);
}

START_ROBOT_CLASS(Robot);

