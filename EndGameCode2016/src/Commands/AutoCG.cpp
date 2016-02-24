#include "AutoCG.h"
#include "../Subsystems/ControlSS.h"
#include "../Commands/Position/Pos1.h"
#include "../Commands/Position/Pos2.h"
#include "../Commands/Position/Pos3.h"
#include "../Commands/Position/Pos4.h"
#include "../Commands/Position/Pos5.h"
#include "../Commands/Defense/Def1.h"
#include "../Commands/Defense/Def2.h"
#include "../Commands/Defense/Def3.h"
#include "../Commands/Defense/Def4.h"
#include "../Commands/Defense/Def5.h"
#include "../Commands/Defense/Def6.h"
#include "../Commands/Defense/Def7.h"
#include "../Commands/Defense/Def8.h"
#include "../Commands/Defense/Def9.h"
#include "../Commands/Movement/DriveC.h"
#include "../Commands/Arm/extend.h"
#include "../Commands/Arm/retract.h"
#include "../Commands/Arm/rotateIn.h"
#include "../Commands/Arm/rotateOut.h"
#include "../Commands/Shooter/fireC.h"
#include "../Commands/Shooter/loadC.h"
#include "../Commands/Shooter/releaseC.h"
#include "../Commands/Shooter/manualLoaderToggle.h"
#include "../Commands/Shooter/manualLatchToggle.h"
#include "../Commands/sensitivityFalse.h"
#include "../Commands/sensitivityTrue.h"
#include "AutoCG.h"
#include "../Commands/Movement/DriveReverse.h"
#include "../Commands/Movement/DriveReverseSlow.h"
#include "../Commands/Defense/Def1CG.h"
#include "../Commands/Defense/Def2CG.h"
#include "../Commands/Defense/Def3CG.h"
#include "../Commands/Defense/Def4CG.h"
#include "../Commands/Defense/Def5CG.h"
#include "../Commands/Defense/Def6CG.h"
#include "../Commands/Defense/Def7CG.h"
#include "../Commands/Defense/Def8CG.h"
#include "../Commands/Defense/Def9CG.h"
#include "../Commands/After/After1CG.h"
#include "../Commands/After/After2CG.h"
#include "../Commands/After/After3CG.h"
#include "../Commands/After/After4CG.h"
#include "../Commands/After/After5CG.h"
#include "../Commands/Before/Before1CG.h"
#include "../Commands/Before/Before2CG.h"
#include "../Commands/Before/Before3CG.h"
#include "../Commands/Intake/intakeDown.h"
#include "../Commands/Intake/intakeUp.h"
#include "../Commands/CalibrateCG.h"
#include "../Commands/Shooter/UnlockShooter.h"
#include "../Commands/Movement/SlowTurnLeft.h"
#include "../Commands/Movement/SlowTurnRight.h"
#include "../Commands/Movement/SmallReverse.h"
#include "../Commands/Shooter/FireCG.h"
#include "../Commands/Movement/OrientLeft.h"
#include "../Commands/Movement/OrientRight.h"

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
