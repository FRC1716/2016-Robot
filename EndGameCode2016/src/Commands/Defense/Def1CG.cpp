#include "Def1CG.h"
#include "../Movement/DriveToDefense.h"
#include "../Defense/Def1.h"
#include "../Movement/DriveReverse.h"
#include "../Movement/DriveReverseSlow.h"
#include "../Movement/DriveForwardSlow.h"
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
