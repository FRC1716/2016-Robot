#include "Robot.h"

std::shared_ptr<ControlSS> Robot::controlSS;
std::shared_ptr<DriveSubsystem> Robot::driveSubsystem;
std::unique_ptr<OI> Robot::oi;

void Robot::RobotInit() {
	RobotMap::init();

	controlSS.reset(new ControlSS());
    driveSubsystem.reset(new DriveSubsystem());

	oi.reset(new OI());

	//setting up position SC
	Robot::controlSS->posSC = new SendableChooser();
	//adding all options to choose to posSC
	Robot::controlSS->posSC->AddDefault("Left 1 (Default)", new Pos1());
	Robot::controlSS->posSC->AddObject("Left/Middle 2", new Pos2());
	Robot::controlSS->posSC->AddObject("Middle 3", new Pos3());
	Robot::controlSS->posSC->AddObject("Right/Middle 4", new Pos4());
	Robot::controlSS->posSC->AddObject("Right 5", new Pos5());

	//make options viewable on dash
	SmartDashboard::PutData("Positions", Robot::controlSS->posSC);

	//setting up defense SC
	Robot::controlSS->defSC = new SendableChooser();
	//adding all options to choose to defSC
	Robot::controlSS->defSC->AddDefault("Rough Terrain 1 (Default)", new Def1CG());
	Robot::controlSS->defSC->AddObject("Portcullis 2", new Def2CG());
	Robot::controlSS->defSC->AddObject("Cheval de Frise 3", new Def3CG());
	Robot::controlSS->defSC->AddObject("Moat 4", new Def4CG());
	Robot::controlSS->defSC->AddObject("Ramparts 5", new Def5CG());
	Robot::controlSS->defSC->AddObject("Drawbridge 6", new Def6CG());
	Robot::controlSS->defSC->AddObject("Sally Port 7", new Def7CG());
	Robot::controlSS->defSC->AddObject("Rock Wall 8", new Def8CG());
	Robot::controlSS->defSC->AddObject("Low Bar 9", new Def9CG());
	//make defSC viewable on dash
	SmartDashboard::PutData("Defense", Robot::controlSS->defSC);

	//setting up sensitivity SC
	Robot::controlSS->senSC = new SendableChooser();
	//adding all options to choose to senSC
	Robot::controlSS->senSC->AddDefault("Normal sensitivity (Default)", new sensitivityFalse());
	Robot::controlSS->senSC->AddObject("Lower sensitivity", new sensitivityTrue());
	//make senSC viewable on dash
	SmartDashboard::PutData("Sensitivity", Robot::controlSS->senSC);

	//setting up after SC
	Robot::controlSS->afterSC = new SendableChooser();
	//adding all options to choose to afterSC
	Robot::controlSS->afterSC->AddDefault("Stop (Default)", new After1CG());
	Robot::controlSS->afterSC->AddObject("Attempt shot", new After2CG());
	Robot::controlSS->afterSC->AddObject("Defeat current defense", new After3CG());
	Robot::controlSS->afterSC->AddObject("Attempt breaching right defense", new After4CG());
	Robot::controlSS->afterSC->AddObject("Attempt breaching left defense", new After5CG());
	//make afterSC viewable on dash
	SmartDashboard::PutData("After outer-works", Robot::controlSS->afterSC);

	//setting up before SC
	Robot::controlSS->beforeSC = new SendableChooser();
	//adding all options to choose to beforeSC
	Robot::controlSS->beforeSC->AddDefault("Our defense (Default)", new Before1CG());
	Robot::controlSS->beforeSC->AddObject("Left defense", new Before2CG());
	Robot::controlSS->beforeSC->AddObject("Right defense", new Before3CG());
	//make beforeSC viewable on dash
	SmartDashboard::PutData("Before outer-works", Robot::controlSS->beforeSC);

	Robot::controlSS->gyro->Reset();

	// instantiate the command used for the autonomous period
	autonomousCommand.reset(new AutoCG());
}

void Robot::DisabledInit(){
}

void Robot::DisabledPeriodic() {
	Scheduler::GetInstance()->Run();

	Robot::controlSS->gameTimer->Reset();

	//show on dash what numbers were chosen
	SmartDashboard::PutNumber("Position selected:", Robot::controlSS->posNum);
	SmartDashboard::PutNumber("Defense selected:", Robot::controlSS->defNum);
	SmartDashboard::PutBoolean("Sensitivity:", Robot::driveSubsystem->changeSensitivity);
	SmartDashboard::PutBoolean("Sensitivity:", Robot::controlSS->afterNum);

	SmartDashboard::GetNumber("Input distance: ", Robot::driveSubsystem->dist);

	SmartDashboard::PutNumber("Left encoder", std::abs(Robot::driveSubsystem->leftEncoder->Get()));
	SmartDashboard::PutNumber("Right encoder", std::abs(Robot::driveSubsystem->rightEncoder->Get()));
}

void Robot::AutonomousInit() {
	/*
	//create Command objects to get options selected by SCs
	Command* temp = (Command*) Robot::controlSS->posSC->GetSelected();
	Command* temp2 = (Command*) Robot::controlSS->defSC->GetSelected();
	Command* temp3 = (Command*) Robot::controlSS->senSC->GetSelected();
	Command* temp4 = (Command*) Robot::controlSS->afterSC->GetSelected();
	//run both commands that were chosen
	//temp->Run();
	//temp2->Run();
	//temp3->Run();
	//temp4->Run();
	//show on dash what numbers were chosen
	SmartDashboard::PutNumber("Position selected:", Robot::controlSS->posNum);
	SmartDashboard::PutNumber("Defense selected:", Robot::controlSS->defNum);
	SmartDashboard::PutBoolean("Sensitivity:", Robot::driveSubsystem->changeSensitivity);
	SmartDashboard::PutBoolean("Sensitivity:", Robot::controlSS->afterNum);

	Robot::controlSS->updateGyro();
	SmartDashboard::PutNumber("Gyro angle: ", Robot::controlSS->angle);
	SmartDashboard::PutNumber("DB/String 0", Robot::controlSS->angle);

	SmartDashboard::PutNumber("Left Joystick:", Robot::oi->getJoystickLeft()->GetY());
	SmartDashboard::PutNumber("Right Joystick:", Robot::oi->getJoystickRight()->GetY());

	SmartDashboard::GetNumber("Input distance: ", Robot::driveSubsystem->dist);

	SmartDashboard::PutNumber("Left encoder", std::abs(Robot::driveSubsystem->leftEncoder->Get()));
	SmartDashboard::PutNumber("Right encoder", std::abs(Robot::driveSubsystem->rightEncoder->Get()));

	//Reset encoders
		Robot::driveSubsystem->leftEncoder->Reset();
		Robot::driveSubsystem->rightEncoder->Reset();
*/
	if (autonomousCommand.get() != nullptr){
		Robot::controlSS->gameTimer->Reset();
		autonomousCommand->Start();
	}
}

void Robot::AutonomousPeriodic() {
/*
	//create Command objects to get options selected by SCs
	Command* temp = (Command*) Robot::controlSS->posSC->GetSelected();
	Command* temp2 = (Command*) Robot::controlSS->defSC->GetSelected();
	Command* temp3 = (Command*) Robot::controlSS->senSC->GetSelected();
	Command* temp4 = (Command*) Robot::controlSS->afterSC->GetSelected();
	//run both commands that were chosen
	temp->Run();
	temp2->Run();
	temp3->Run();
	temp4->Run();
*/
	//show on dash what numbers were chosen
	SmartDashboard::PutNumber("Position selected:", Robot::controlSS->posNum);
	SmartDashboard::PutNumber("Defense selected:", Robot::controlSS->defNum);
	SmartDashboard::PutBoolean("Sensitivity:", Robot::driveSubsystem->changeSensitivity);
	SmartDashboard::PutBoolean("Sensitivity:", Robot::controlSS->afterNum);

	Robot::controlSS->updateGyro();
	SmartDashboard::PutNumber("Gyro angle: ", Robot::controlSS->angle);
	SmartDashboard::PutNumber("DB/String 0", Robot::controlSS->angle);

	SmartDashboard::PutNumber("Auto Time", Robot::controlSS->gameTimer->Get());

	SmartDashboard::PutBoolean("Loader 1: ", Robot::controlSS->loaderSol[0]->Get());
	SmartDashboard::PutBoolean("Loader 2: ", Robot::controlSS->loaderSol[1]->Get());
	SmartDashboard::PutBoolean("Latch 1: ", Robot::controlSS->latchSol[0]->Get());
	SmartDashboard::PutBoolean("Latch 2: ", Robot::controlSS->latchSol[1]->Get());
	SmartDashboard::PutBoolean("Front Limit Switch: ", Robot::controlSS->frontLS->Get());
	SmartDashboard::PutBoolean("Side Limit Switch: ", Robot::controlSS->sideLS->Get());
	SmartDashboard::PutBoolean("Back Limit Switch: ", Robot::controlSS->backLS->Get());
	SmartDashboard::PutBoolean("Loaded: ", Robot::controlSS->loaded);

	SmartDashboard::PutNumber("Left Joystick:", Robot::oi->getJoystickLeft()->GetY());
	SmartDashboard::PutNumber("Right Joystick:", Robot::oi->getJoystickRight()->GetY());

	SmartDashboard::GetNumber("Input distance: ", Robot::driveSubsystem->dist);

	SmartDashboard::PutNumber("Left encoder", std::abs(Robot::driveSubsystem->leftEncoder->Get()));
	SmartDashboard::PutNumber("Right encoder", std::abs(Robot::driveSubsystem->rightEncoder->Get()));

	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// these lines or comment it out.
	/*
	Command* temp3 = (Command*) Robot::controlSS->senSC->GetSelected();
	//temp3->Run();
	SmartDashboard::PutBoolean("Sensitivity:", Robot::driveSubsystem->changeSensitivity);

	Robot::controlSS->updateGyro();
	SmartDashboard::PutNumber("Gyro angle: ", Robot::controlSS->angle);
	SmartDashboard::PutNumber("DB/String 0", Robot::controlSS->angle);

	SmartDashboard::PutNumber("Left Joystick:", Robot::oi->getJoystickLeft()->GetY());
	SmartDashboard::PutNumber("Right Joystick:", Robot::oi->getJoystickRight()->GetY());

	SmartDashboard::GetNumber("Input distance: ", Robot::driveSubsystem->dist);
	*/

	if (autonomousCommand.get() != nullptr){
		Robot::controlSS->gameTimer->Reset();
		autonomousCommand->Cancel();
	}
}

void Robot::TeleopPeriodic() {
	Command* temp3 = (Command*) Robot::controlSS->senSC->GetSelected();
	//temp3->Run();
	SmartDashboard::PutBoolean("Sensitivity:", Robot::driveSubsystem->changeSensitivity);

	SmartDashboard::PutNumber("Teleop Time", Robot::controlSS->gameTimer->Get());

	Robot::controlSS->updateGyro();
	SmartDashboard::PutNumber("Gyro angle: ", Robot::controlSS->angle);
	SmartDashboard::PutNumber("DB/String 0", Robot::controlSS->angle);

	SmartDashboard::PutBoolean("Loader 1: ", Robot::controlSS->loaderSol[0]->Get());
	SmartDashboard::PutBoolean("Loader 2: ", Robot::controlSS->loaderSol[1]->Get());
	SmartDashboard::PutBoolean("Latch 1: ", Robot::controlSS->latchSol[0]->Get());
	SmartDashboard::PutBoolean("Latch 2: ", Robot::controlSS->latchSol[1]->Get());
	SmartDashboard::PutBoolean("Front Limit Switch: ", Robot::controlSS->frontLS->Get());
	SmartDashboard::PutBoolean("Side Limit Switch: ", Robot::controlSS->sideLS->Get());
	SmartDashboard::PutBoolean("Back Limit Switch: ", Robot::controlSS->backLS->Get());
	SmartDashboard::PutBoolean("Loaded: ", Robot::controlSS->loaded);

	SmartDashboard::PutNumber("Left Joystick:", Robot::oi->getJoystickLeft()->GetY());
	SmartDashboard::PutNumber("Right Joystick:", Robot::oi->getJoystickRight()->GetY());

	SmartDashboard::GetNumber("Input distance: ", Robot::driveSubsystem->dist);

	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Robot);

