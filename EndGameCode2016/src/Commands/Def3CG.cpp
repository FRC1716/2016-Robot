#include "Def3CG.h"
#include "../Robot.h"
#include "../Commands/DriveToDefense.h"

Def3CG::Def3CG()
{
	//CHEVAL DE FRISE
	//sets values based on this defense
	Robot::controlSS->canBreach = true;
	Robot::controlSS->canReverse = true;
	//drive to defense
	AddSequential(new DriveToDefense);
	//wait to code rest
}
