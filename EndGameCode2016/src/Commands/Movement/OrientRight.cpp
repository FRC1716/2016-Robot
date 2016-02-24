#include "OrientRight.h"

OrientRight::OrientRight(): Command(){
	Requires(Robot::driveSubsystem.get());
}

void OrientRight::Initialize(){
}

void OrientRight::Execute(){
}

bool OrientRight::IsFinished(){
	return false;
}

void OrientRight::End(){
}

void OrientRight::Interrupted(){
}
