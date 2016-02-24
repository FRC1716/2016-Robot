#include "OrientLeft.h"

OrientLeft::OrientLeft(): Command(){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(Robot::driveSubsystem.get());
}

// Called just before this Command runs the first time
void OrientLeft::Initialize(){

}

// Called repeatedly when this Command is scheduled to run
void OrientLeft::Execute(){

}

// Make this return true when this Command no longer needs to run execute()
bool OrientLeft::IsFinished(){
	return false;
}

// Called once after isFinished returns true
void OrientLeft::End(){

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OrientLeft::Interrupted(){

}
