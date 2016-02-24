#include "ControlSS.h"
#include "../RobotMap.h"

ControlSS::ControlSS() : Subsystem("ControlSS") {
	//initialize all variables
	//all number type variables
	posNum = 0;
	defNum = 0;
	afterNum = 0;
	windowNum = 0;
	firingPressure = 70;
	loadingPressure = 110;
	beginTime = 0.0;
	angle = 0.0f;

	//all boolean type variables
	canBreach = false;
	canReverse = false;
	loaded = false;
	locked = true;

	//all timer type variables
	gameTimer = new Timer();
	gameTimer->Start();

    armAngle1 = RobotMap::controlSSarmAngle1;
    armAngle2 = RobotMap::controlSSarmAngle2;
    armExtend1 = RobotMap::controlSSarmExtend1;
    gyro = RobotMap::controlSSgyro;
    frontLS = RobotMap::controlSSfrontLS;
    backLS = RobotMap::controlSSbackLS;
    sideLS = RobotMap::controlSSsideLS;

    gyro->Reset();

    latchSol[0] = RobotMap::controlSSsolenoid0;
    latchSol[1] = RobotMap::controlSSsolenoid1;
    loaderSol[0] = RobotMap::controlSSsolenoid2;
    loaderSol[1] = RobotMap::controlSSsolenoid3;

    pressureGauge = RobotMap::controlSSpressureGauge;

    loaderState = loaderSol[0]->Get();
    latchState = latchSol[0]->Get();
    updateSols(0);

    intakeMotor = RobotMap::controlSSintake;

    //initialize a text box on smartdashboard
    SmartDashboard::PutString("Messages: ", "---");
}

void ControlSS::InitDefaultCommand() {
}

//position methods
//sets position number to 1
void ControlSS::setPos1(){
	posNum = 1;
}
//sets position number to 2
void ControlSS::setPos2(){
	posNum = 2;
}
//sets position number to 3
void ControlSS::setPos3(){
	posNum = 3;
}
//sets position number to 4
void ControlSS::setPos4(){
	posNum = 4;
}
//sets position number to 5
void ControlSS::setPos5(){
	posNum = 5;
}

//methods for arm
//rotates arm out
void ControlSS::out() {
	armAngle1->Set(-1);
	armAngle2->Set(1);
}
//rotates arm in
void ControlSS::in(){
	armAngle1->Set(1);
	armAngle2->Set(-1);
}
//extends arm
void ControlSS::extend(){
	armExtend1->Set(1);
}
//retracts arm
void ControlSS::retract(){
	armExtend1->Set(-1);
}
//stops arm extension motors
void ControlSS::stopLinear(){
	armExtend1->Set(0);
}
//stops arm rotation motors
void ControlSS::stopRotate(){
	armAngle1->Set(0);
	armAngle2->Set(0);
}

//gyro methods
//updates angle using gyro
void ControlSS::updateGyro(){
	angle = gyro->GetAngle();
}

//utility methods
//starts the timer
void ControlSS::startTimer(){
	beginTime = clock();
}
//returns the time that has passed
double ControlSS::elapsedTime(){
	return ((double) clock() - beginTime) * CLOCKS_PER_SEC;
}

//shooter methods
//cylinder
   /* 0 = none
    * 1 = loader
    * 2 = latch
    */
//toggles the values of the inputed cylinder
void ControlSS::toggle(int cylinder){
	if (cylinder == 1){
		SmartDashboard::PutString("Messages: ", "toggling loader...");

		latchState = latchSol[latchState == latchSol[0]->Get() ? 1 : 0]->Get();

		SmartDashboard::PutString("Messages: ", latchSol[0]->Get() == latchState ? "Raising latch..." : "Dropping latch...");
	}else if (cylinder == 2){
		SmartDashboard::PutString("Messages: ", "toggling latch...");

		loaderState = loaderSol[loaderState == loaderSol[0]->Get() ? 1 : 0]->Get();

		SmartDashboard::PutString("Messages: ", loaderSol[0]->Get() == loaderState ? "Resetting loading slide..." : "Pushing loading slide...");
	}

	updateSols(cylinder);
}
//sets a value to a solenoid to true and doesn't care about the current value
void ControlSS::setSols(int cylinder, int state){


	if (cylinder == 1){
		loaderState = loaderSol[state]->Get();

		if (state == 0){
			SmartDashboard::PutString("Messages: ", "setting loading 1 to HIGH");
		}else if (state == 1){
			SmartDashboard::PutString("Messages: ", "setting loading 2 to HIGH");
		}

		updateSols(1);
	}else if (cylinder == 2){
		latchState = latchSol[state]->Get();

		if (state == 0){
			SmartDashboard::PutString("Messages: ", "setting latch 1 to HIGH");
		}else if (state == 1){
			SmartDashboard::PutString("Messages: ", "setting latch 2 to HIGH");
		}

		updateSols(2);
	}
}
//sets all the relays to a value of 0
void ControlSS::allSolsLow(){
	SmartDashboard::PutString("Messages: ", "reseting all solenoids...");

	latchSol[0]->Set(false);
	latchSol[1]->Set(false);
	loaderSol[0]->Set(false);
	loaderSol[1]->Set(false);

	SmartDashboard::PutString("Messages: ", "solenoids reset");
}
//opens the solenoid that is selected
void ControlSS::updateSols(int cylinder){
	if (cylinder == 0 || cylinder == 1){
		if (loaderState == 0){
			loaderSol[0]->Set(1);
		}else if (loaderState == 1){
			loaderSol[1]->Set(1);
		}
	}

	if (cylinder == 0 || cylinder == 2){
		if (latchState == 0){
			latchSol[0]->Set(1);
		}else if (latchState == 1){
			latchSol[1]->Set(1);
		}
	}

	Wait(0.2);

	allSolsLow();
}
//gets in PSI from analogInput and makes sure that it is over a value
void ControlSS::waitForPSI(int x){
	double PSI = (pressureGauge->GetValue()) * 0.255 - 25.427;

	while(PSI < x){
		PSI = (pressureGauge->GetValue()) * 0.255 - 25.427;
	}
}
//resets the solenoid pair back to default state
void ControlSS::reset(){
	setSols(1, 0);
	setSols(2, 0);
	SmartDashboard::PutString("Messages: ", "Reset complete");
}
//runs all set sequences based on x
void ControlSS::runSequence(int x){
	/* 1 = toggle loader NOT USED
	 * 2 = toggle latch NOT USED
	 * 3 = reset NOT USED
	 * 4 = fire
	 * 5 = assisted release
	 * 6 = load
	 * NOTE: the state request was removed because it is always happening in Robot.cpp
	 */

	if (x == 1){

		toggle(1);

	}else if (x == 2){

		toggle(2);

	}else if (x == 3){

		SmartDashboard::PutString("Messages: ", "Resetting...");
		reset();

	}else if (x == 4){

		SmartDashboard::PutString("Messages: ", "Starting firing sequence");
		SmartDashboard::PutString("Messages: ", "waiting for pressure...");

		waitForPSI(firingPressure);

		SmartDashboard::PutString("Messages: ", "releasing latch...Firing!");

		setSols(2, 1);

		SmartDashboard::PutString("Messages: ", "waiting for bucket to reset...");

		while(sideLS->Get() == true){
			sideLS->Get();
		}

		SmartDashboard::PutString("Messages: ", "locking latch...");

		setSols(2, 0);

		SmartDashboard::PutString("Messages: ", "Firing sequence complete");

	}else if (x == 5){

		SmartDashboard::PutString("Messages: ", "Starting assisted release");
		SmartDashboard::PutString("Messages: ", "waiting on pressure...");

		waitForPSI(loadingPressure);

		SmartDashboard::PutString("Messages: ", "Pushing loading slide");
		SmartDashboard::PutString("Messages: ", "waiting on pressure...");

		waitForPSI(firingPressure);

		SmartDashboard::PutString("Messages: ", "releasing latch...");

		setSols(2, 1);

		SmartDashboard::PutString("Messages: ", "releasing loader...");

		setSols(1, 0);

		SmartDashboard::PutString("Messages: ", "waiting for loader to vacate...");

		while(sideLS->Get() == true){
			//nothing needed here yet
		}

		SmartDashboard::PutString("Messages: ", "locking latch...");

		setSols(2, 0);

		SmartDashboard::PutString("Messages: ", "Completed assisted release");

	}else if (x == 6){

		SmartDashboard::PutString("Messages: ", "Starting loading sequence");
		SmartDashboard::PutString("Messages: ", "locking latch...");

		setSols(2, 0);

		SmartDashboard::PutString("Messages: ", "waiting on pressure...");

		waitForPSI(loadingPressure);

		SmartDashboard::PutString("Messages: ", "pushing loading slide...");

		setSols(1, 1);

		while(backLS->Get() == 0){
			//nothing needed here yet
		}

		SmartDashboard::PutString("Messages: ", "loading slide pushed");
		SmartDashboard::PutString("Messages: ", "resetting loading slide...");

		setSols(1, 0);

		while(frontLS->Get() == 0){
			//nothing needed here yet
		}

		loaded = true;
		SmartDashboard::PutString("Messages: ", "Loading sequence complete");
	}

}
//unlocks the fire button
void ControlSS::unlockShooter(){
	locked = false;
}
//relocks fire button
void ControlSS::lockShooter(){
	locked = true;
}

//methods for intake
//moves intake up
void ControlSS::UpIntake() {
	intakeMotor->Set(0.3);
}
//moves intake down
void ControlSS::DownIntake() {
	intakeMotor->Set(-0.3);
}
//stops intake
void ControlSS::StopIntake(){
	intakeMotor->Set(0.0);
}
