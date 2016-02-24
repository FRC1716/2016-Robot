#include "Def2CG.h"
#include "../Robot.h"
#include "../Commands/DriveToDefense.h"
#include "../Commands/Def2.h"

Def2CG::Def2CG()
{
	//PORTCULLIS
	//sets values based on this defense
	Robot::controlSS->canBreach = true;
	Robot::controlSS->canReverse = true;
	Robot::controlSS->defNum = 2;
	//drives to the defense
	AddSequential(new DriveToDefense);
	//does stuff with defense
	AddSequential(new Def2);
}
