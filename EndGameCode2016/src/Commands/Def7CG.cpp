#include "Def7CG.h"
#include "../Robot.h"
#include "../Commands/DriveToDefense.h"
#include "../Commands/Def7.h"

Def7CG::Def7CG()
{
	//SALLY PORT
	//sets values based on this defense
	Robot::controlSS->canBreach = false;
	Robot::controlSS->canReverse = true;
	//drive to defense
	AddSequential(new DriveToDefense);
	//do stuff with defense
	AddSequential(new Def7);
}
