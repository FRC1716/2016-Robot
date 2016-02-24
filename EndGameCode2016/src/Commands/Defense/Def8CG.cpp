#include "Def8CG.h"
#include "../../Robot.h"
#include "../Movement/DriveToDefense.h"
#include "../Defense/Def8.h"
#include "../Movement/DriveForwardSlow.h"

Def8CG::Def8CG()
{
	//ROCK WALL
	//sets values based on this defense
	Robot::controlSS->canBreach = true;
	Robot::controlSS->canReverse = false;
	Robot::controlSS->defNum = 8;
	//drive to defense
	AddSequential(new DriveToDefense);
	//do stuff with defense
	AddSequential(new Def8);
	//slow down end drive
	AddSequential(new DriveForwardSlow);
}
