#include "OrientRight.h"

OrientRight::OrientRight(): Command(){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::driveSubsystem.get());
}

// Called just before this Command runs the first time
void OrientRight::Initialize(){

}

// Called repeatedly when this Command is scheduled to run
void OrientRight::Execute(){

}

// Make this return true when this Command no longer needs to run execute()
bool OrientRight::IsFinished(){
	return false;
}

// Called once after isFinished returns true
void OrientRight::End(){

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OrientRight::Interrupted(){

}
