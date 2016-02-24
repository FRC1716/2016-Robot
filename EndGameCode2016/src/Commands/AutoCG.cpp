#include "AutoCG.h"
#include "../Subsystems/ControlSS.h"
#include "../Commands/Pos1.h"
#include "../Commands/Pos2.h"
#include "../Commands/Pos3.h"
#include "../Commands/Pos4.h"
#include "../Commands/Pos5.h"
#include "../Commands/Def1.h"
#include "../Commands/Def2.h"
#include "../Commands/Def3.h"
#include "../Commands/Def4.h"
#include "../Commands/Def5.h"
#include "../Commands/Def6.h"
#include "../Commands/Def7.h"
#include "../Commands/Def8.h"
#include "../Commands/Def9.h"
#include "../Commands/DriveC.h"
#include "../Commands/extend.h"
#include "../Commands/retract.h"
#include "../Commands/rotateIn.h"
#include "../Commands/rotateOut.h"
#include "../Commands/fireC.h"
#include "../Commands/loadC.h"
#include "../Commands/releaseC.h"
#include "../Commands/manualLoaderToggle.h"
#include "../Commands/manualLatchToggle.h"
#include "../Commands/sensitivityFalse.h"
#include "../Commands/sensitivityTrue.h"
#include "../Commands/Def1CG.h"
#include "../Commands/Def2CG.h"
#include "../Commands/Def3CG.h"
#include "../Commands/Def4CG.h"
#include "../Commands/Def5CG.h"
#include "../Commands/Def6CG.h"
#include "../Commands/Def7CG.h"
#include "../Commands/Def8CG.h"
#include "../Commands/Def9CG.h"
#include "../Commands/DriveToDefense.h"
#include "../Commands/AutonomousCommand.h"
#include "../Commands/DriveReverse.h"
#include "../Commands/DriveReverseSlow.h"
#include "../Commands/After1CG.h"
#include "../Commands/After2CG.h"
#include "../Commands/After3CG.h"
#include "../Commands/After4CG.h"
#include "../Commands/After5CG.h"
#include "../Commands/Before1CG.h"
#include "../Commands/Before2CG.h"
#include "../Commands/Before3CG.h"
#include "../Commands/intakeDown.h"
#include "../Commands/intakeUp.h"

AutoCG::AutoCG()
{
	//get all SCs that are needed for auto
	def = (CommandGroup*) Robot::controlSS->defSC->GetSelected();
	before = (CommandGroup*) Robot::controlSS->beforeSC->GetSelected();
	after = (CommandGroup*) Robot::controlSS->afterSC->GetSelected();
	pos = Robot::controlSS->posNum;

	//start by running the before command
	before->Run();
	//start the command for the defense we are in front of
	def->Run();
	//finish by running the after command
	after->Run();
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.

	/*AddSequential(new DriveToDefense);
	AddSequential(new AutonomousCommand);
	AddSequential(new DriveReverseSlow);
	Robot::driveSubsystem->Stop();
	AddSequential(new DriveReverse);
	AddSequential(new Def1CG);*/
	//AddSequential(new AutonomousCommand);
}
