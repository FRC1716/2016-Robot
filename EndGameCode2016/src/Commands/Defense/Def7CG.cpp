#include "Def7CG.h"
#include "../../Robot.h"
#include "../Movement/DriveToDefense.h"
#include "../Defense/Def7.h"

Def7CG::Def7CG()
{
	//SALLY PORT
	//sets values based on this defense
	Robot::controlSS->canBreach = false;
	Robot::controlSS->canReverse = true;
	Robot::controlSS->defNum = 7;
	//drive to defense
	AddSequential(new DriveToDefense);
	//do stuff with defense
	AddSequential(new Def7);
}
