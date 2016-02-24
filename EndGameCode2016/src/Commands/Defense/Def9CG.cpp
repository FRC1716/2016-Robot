#include "Def9CG.h"
#include "../../Robot.h"
#include "../Movement/DriveToDefense.h"
#include "../Defense/Def9.h"

Def9CG::Def9CG()
{
	//LOW BAR
	//sets values based on this defense
	Robot::controlSS->canBreach = false;
	Robot::controlSS->canReverse = false;
	Robot::controlSS->defNum = 9;
	//drive to defense
	AddSequential(new DriveToDefense);
	//do stuff with defense
	AddSequential(new Def9);
}
