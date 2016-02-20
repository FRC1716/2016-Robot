// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Joystick> joystickRight;
	std::shared_ptr<Joystick> joystickLeft;
	std::shared_ptr<JoystickButton> joystickRB2;
	std::shared_ptr<JoystickButton> joystickRB1;
	//std::shared_ptr<JoystickButton> joystickLB11;
	//std::shared_ptr<JoystickButton> joystickLB10;
	//std::shared_ptr<JoystickButton> joystickLB3;
	//std::shared_ptr<JoystickButton> joystickLB2;
	//std::shared_ptr<JoystickButton> joystickLB1;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<Joystick> getJoystickLeft();
	std::shared_ptr<Joystick> getJoystickRight();
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};

#endif
