#include "Def6CG.h"
#include "../../Robot.h"
#include "../../Commands/Movement/DriveToDefense.h"
#include "../../Commands/Defense/Def6.h"

Def6CG::Def6CG()
{
	//DRAWBRIDGE
	//sets values based on this defense
	Robot::controlSS->canBreach = false;
	Robot::controlSS->canReverse = true;
	Robot::controlSS->defNum = 6;
	//drive to defense
	AddSequential(new DriveToDefense);
	//do stuff with defense
	AddSequential(new Def6);
}
