#include "Def1CG.h"
#include "../../Commands/Movement/DriveToDefense.h"
#include "../../Commands/Defense/Def1.h"
#include "../../Commands/Movement/DriveReverse.h"
#include "../../Commands/Movement/DriveReverseSlow.h"
#include "../../Commands/Movement/DriveForwardSlow.h"
#include "../../Robot.h"

Def1CG::Def1CG()
{
	//ROUGH TERRAIN
	//sets values based on this defense
	Robot::controlSS->canBreach = true;
	Robot::controlSS->canReverse = true;
	Robot::controlSS->defNum = 1;
	//drives up to defense
	AddSequential(new DriveToDefense);
	//does stuff with defense
	AddSequential(new Def1);
	//slows down end driving
	AddSequential(new DriveForwardSlow);
}
