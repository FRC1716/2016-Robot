#include "After3CG.h"
#include "../../Commands/Movement/DriveReverse.h"
#include "../../Commands/Movement/DriveReverseSlow.h"
#include "../../Robot.h"

After3CG::After3CG()
{
	//DEFEAT CURRENT DEFENSE
	//checks to see if it can (should) be done
	if (Robot::controlSS->canReverse == true){
		//drives backwards over defense
		AddSequential(new DriveReverse);
		//drives backwards slowly
		AddSequential(new DriveReverseSlow);
		//runs current defense command group again
		def = (CommandGroup*) Robot::controlSS->defSC->GetSelected();
	}
}
