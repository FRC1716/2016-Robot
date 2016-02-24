#include "After1CG.h"
#include "../../Robot.h"

After1CG::After1CG()
{
	//STOP
	//stops the robot
	Robot::driveSubsystem->Stop();
}
