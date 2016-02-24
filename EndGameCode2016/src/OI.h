#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	//joysticks
	std::shared_ptr<Joystick> joystickRight;
	std::shared_ptr<Joystick> joystickLeft;
	std::shared_ptr<Joystick> joystickShooter;
	//buttons for right joystick
	std::shared_ptr<JoystickButton> joystickRB1;
	std::shared_ptr<JoystickButton> joystickRB2;
	std::shared_ptr<JoystickButton> joystickRB3;
	std::shared_ptr<JoystickButton> joystickRB4;
	std::shared_ptr<JoystickButton> joystickRB5;
	std::shared_ptr<JoystickButton> joystickRB11;
	//buttons for left joystick
	std::shared_ptr<JoystickButton> joystickLB1;
	std::shared_ptr<JoystickButton> joystickLB2;
	std::shared_ptr<JoystickButton> joystickLB3;
	std::shared_ptr<JoystickButton> joystickLB11;
	std::shared_ptr<JoystickButton> joystickLB10;
	//buttons for shooter joystick (FULL)
	std::shared_ptr<JoystickButton> joystickSB1;
	std::shared_ptr<JoystickButton> joystickSB2;
	std::shared_ptr<JoystickButton> joystickSB3;
	std::shared_ptr<JoystickButton> joystickSB4;
	std::shared_ptr<JoystickButton> joystickSB5;
	std::shared_ptr<JoystickButton> joystickSB6;
	std::shared_ptr<JoystickButton> joystickSB7;
public:
	OI();

	std::shared_ptr<Joystick> getJoystickLeft();
	std::shared_ptr<Joystick> getJoystickRight();
	std::shared_ptr<Joystick> getJoystickShooter();
};

#endif
