#ifndef _ROBOT_H
#define _ROBOT_H

#include "WPILib.h"
#include "Commands/Command.h"
#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

#include "Subsystems/ControlSS.h"
#include "Subsystems/DriveSubsystem.h"
#include "SmartDashboard/SmartDashboard.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Subsystems/ControlSS.h"
#include "Commands/Position/Pos1.h"
#include "Commands/Position/Pos2.h"
#include "Commands/Position/Pos3.h"
#include "Commands/Position/Pos4.h"
#include "Commands/Position/Pos5.h"
#include "Commands/Defense/Def1.h"
#include "Commands/Defense/Def2.h"
#include "Commands/Defense/Def3.h"
#include "Commands/Defense/Def4.h"
#include "Commands/Defense/Def5.h"
#include "Commands/Defense/Def6.h"
#include "Commands/Defense/Def7.h"
#include "Commands/Defense/Def8.h"
#include "Commands/Defense/Def9.h"
#include "Commands/Movement/DriveC.h"
#include "Commands/Arm/extend.h"
#include "Commands/Arm/retract.h"
#include "Commands/Arm/rotateIn.h"
#include "Commands/Arm/rotateOut.h"
#include "Commands/Shooter/fireC.h"
#include "Commands/Shooter/loadC.h"
#include "Commands/Shooter/releaseC.h"
#include "Commands/Shooter/manualLoaderToggle.h"
#include "Commands/Shooter/manualLatchToggle.h"
#include "Commands/sensitivityFalse.h"
#include "Commands/sensitivityTrue.h"
#include "Commands/AutoCG.h"
#include "Commands/Movement/DriveReverse.h"
#include "Commands/Movement/DriveReverseSlow.h"
#include "Commands/Defense/Def1CG.h"
#include "Commands/Defense/Def2CG.h"
#include "Commands/Defense/Def3CG.h"
#include "Commands/Defense/Def4CG.h"
#include "Commands/Defense/Def5CG.h"
#include "Commands/Defense/Def6CG.h"
#include "Commands/Defense/Def7CG.h"
#include "Commands/Defense/Def8CG.h"
#include "Commands/Defense/Def9CG.h"
#include "Commands/After/After1CG.h"
#include "Commands/After/After2CG.h"
#include "Commands/After/After3CG.h"
#include "Commands/After/After4CG.h"
#include "Commands/After/After5CG.h"
#include "Commands/Before/Before1CG.h"
#include "Commands/Before/Before2CG.h"
#include "Commands/Before/Before3CG.h"
#include "Commands/Intake/intakeDown.h"
#include "Commands/Intake/intakeUp.h"
#include "Commands/CalibrateCG.h"
#include "Commands/Shooter/UnlockShooter.h"
#include "Commands/Movement/SlowTurnLeft.h"
#include "Commands/Movement/SlowTurnRight.h"
#include "Commands/Movement/SmallReverse.h"
#include "Commands/Shooter/FireCG.h"
#include "Commands/Movement/OrientLeft.h"
#include "Commands/Movement/OrientRight.h"

#include "OI.h"

class Robot : public IterativeRobot {
public:
	std::unique_ptr<CommandGroup> autonomousCommand;
	static std::unique_ptr<OI> oi;
	LiveWindow *lw = LiveWindow::GetInstance();

	static std::shared_ptr<ControlSS> controlSS;
    static std::shared_ptr<DriveSubsystem> driveSubsystem;

    //create empty commands to hold the options chosen
    Command* temp;
    Command* temp2;
    Command* temp3;
    Command* temp4;

    virtual void RobotInit();
	virtual void DisabledInit();
	virtual void DisabledPeriodic();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};
#endif
