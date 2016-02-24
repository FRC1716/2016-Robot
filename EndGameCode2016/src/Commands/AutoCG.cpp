#include "AutoCG.h"
#include "../Subsystems/ControlSS.h"
#include "Position/Pos1.h"
#include "Position/Pos2.h"
#include "Position/Pos3.h"
#include "Position/Pos4.h"
#include "Position/Pos5.h"
#include "Defense/Def1.h"
#include "Defense/Def2.h"
#include "Defense/Def3.h"
#include "Defense/Def4.h"
#include "Defense/Def5.h"
#include "Defense/Def6.h"
#include "Defense/Def7.h"
#include "Defense/Def8.h"
#include "Defense/Def9.h"
#include "Movement/DriveC.h"
#include "Arm/extend.h"
#include "Arm/retract.h"
#include "Arm/rotateIn.h"
#include "Arm/rotateOut.h"
#include "Shooter/fireC.h"
#include "Shooter/loadC.h"
#include "Shooter/releaseC.h"
#include "Shooter/manualLoaderToggle.h"
#include "Shooter/manualLatchToggle.h"
#include "sensitivityFalse.h"
#include "sensitivityTrue.h"
#include "AutoCG.h"
#include "Movement/DriveReverse.h"
#include "Movement/DriveReverseSlow.h"
#include "Defense/Def1CG.h"
#include "Defense/Def2CG.h"
#include "Defense/Def3CG.h"
#include "Defense/Def4CG.h"
#include "Defense/Def5CG.h"
#include "Defense/Def6CG.h"
#include "Defense/Def7CG.h"
#include "Defense/Def8CG.h"
#include "Defense/Def9CG.h"
#include "After/After1CG.h"
#include "After/After2CG.h"
#include "After/After3CG.h"
#include "After/After4CG.h"
#include "After/After5CG.h"
#include "Before/Before1CG.h"
#include "Before/Before2CG.h"
#include "Before/Before3CG.h"
#include "Intake/intakeDown.h"
#include "Intake/intakeUp.h"
#include "CalibrateCG.h"
#include "Shooter/UnlockShooter.h"
#include "Movement/SlowTurnLeft.h"
#include "Movement/SlowTurnRight.h"
#include "Movement/SmallReverse.h"
#include "Shooter/FireCG.h"
#include "Movement/OrientLeft.h"
#include "Movement/OrientRight.h"

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
