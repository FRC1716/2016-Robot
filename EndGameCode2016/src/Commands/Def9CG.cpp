#include "Def9CG.h"
#include "../Robot.h"
#include "../Commands/DriveToDefense.h"

Def9CG::Def9CG()
{
	//LOW BAR
	//sets values based on this defense
	Robot::controlSS->canBreach = false;
	Robot::controlSS->canReverse = false;
	//drive to defense
	AddSequential(new DriveToDefense);
}
