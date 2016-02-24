#include "Def4CG.h"
#include "../../Robot.h"
#include "../../Commands/Movement/DriveToDefense.h"
#include "../../Commands/Defense/Def4.h"
#include "../../Commands/Movement/DriveForwardSlow.h"

Def4CG::Def4CG()
{
	//MOAT
	//sets values based on this defense
	Robot::controlSS->canBreach = true;
	Robot::controlSS->canReverse = true;
	Robot::controlSS->defNum = 4;
	//drives to defense
	AddSequential(new DriveToDefense);
	//does stuff with defense
	AddSequential(new Def4);
	//slows down end driving
	AddSequential(new DriveForwardSlow);
}
