#include "Def5CG.h"
#include "../Robot.h"
#include "../Commands/DriveToDefense.h"

Def5CG::Def5CG()
{
	//RAMPARTS
	//sets values based on this defense
	Robot::controlSS->canBreach = true;
	Robot::controlSS->canReverse = true;
	//drive to defense
	AddSequential(new DriveToDefense);
	//wait to code rest
}
