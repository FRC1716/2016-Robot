#include "OrientLeft.h"

OrientLeft::OrientLeft(): Command(){
	Requires(Robot::driveSubsystem.get());
}

void OrientLeft::Initialize(){
}

void OrientLeft::Execute(){
}

bool OrientLeft::IsFinished(){
	return false;
}

void OrientLeft::End(){
}

void OrientLeft::Interrupted(){
}
