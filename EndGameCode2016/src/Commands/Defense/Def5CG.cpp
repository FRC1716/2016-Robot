#include "../Defense/Def5CG.h"

#include "../../Robot.h"
#include "../../Commands/Movement/DriveToDefense.h"

Def5CG::Def5CG()
{
	//RAMPARTS
	//sets values based on this defense
	Robot::controlSS->canBreach = true;
	Robot::controlSS->canReverse = true;
	Robot::controlSS->defNum = 5;
	//drive to defense
	AddSequential(new DriveToDefense);
	//wait to code rest
}
