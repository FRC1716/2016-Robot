#include "OI.h"

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

OI::OI() {
	//joysticks
    joystickLeft.reset(new Joystick(0));
    joystickRight.reset(new Joystick(1));
    joystickShooter.reset(new Joystick(2));

    //left joystick buttons
    joystickLB1.reset(new JoystickButton(joystickLeft.get(), 1));
    	joystickLB1->WhenPressed(new FireCG());
    joystickLB2.reset(new JoystickButton(joystickLeft.get(), 2));
    	joystickLB2->WhenPressed(new intakeDown());
    joystickLB3.reset(new JoystickButton(joystickLeft.get(), 3));
    	joystickLB3->WhenPressed(new intakeUp());
    joystickLB10.reset(new JoystickButton(joystickLeft.get(), 10));
    	joystickLB10->WhenPressed(new manualLoaderToggle());
    joystickLB11.reset(new JoystickButton(joystickLeft.get(), 11));
    	joystickLB11->WhenPressed(new manualLatchToggle());

    //right joystick buttons
    joystickRB1.reset(new JoystickButton(joystickRight.get(), 1));
    joystickRB2.reset(new JoystickButton(joystickRight.get(), 2));
    	joystickRB2->WhileHeld(new rotateIn());
    joystickRB3.reset(new JoystickButton(joystickRight.get(), 3));
    	joystickRB3->WhileHeld(new rotateOut());
    joystickRB4.reset(new JoystickButton(joystickRight.get(), 4));
    	joystickRB4->WhileHeld(new extend());
    joystickRB5.reset(new JoystickButton(joystickRight.get(), 5));
    	joystickRB5->WhileHeld(new retract());
    joystickRB11.reset(new JoystickButton(joystickRight.get(), 11));
    	 joystickRB11->WhenPressed(new CalibrateCG());

    //shooter joystick buttons
    joystickSB1.reset(new JoystickButton(joystickShooter.get(), 1));
    	joystickSB1->WhenPressed(new FireCG());
    joystickSB2.reset(new JoystickButton(joystickShooter.get(), 2));
    	joystickSB2->WhileHeld(new UnlockShooter());
    joystickSB3.reset(new JoystickButton(joystickShooter.get(), 3));
    	joystickSB3->WhileHeld(new SlowTurnLeft());
    joystickSB4.reset(new JoystickButton(joystickShooter.get(), 4));
    	joystickSB4->WhileHeld(new SlowTurnRight());
    joystickSB5.reset(new JoystickButton(joystickShooter.get(), 5));
    	joystickSB5->WhenPressed(new loadC());
    joystickSB6.reset(new JoystickButton(joystickShooter.get(), 6));
    	joystickSB6->WhenPressed(new releaseC());
}

std::shared_ptr<Joystick> OI::getJoystickLeft() {
   return joystickLeft;
}

std::shared_ptr<Joystick> OI::getJoystickRight() {
   return joystickRight;
}

std::shared_ptr<Joystick> OI::getJoystickShooter(){
	return joystickShooter;
}
