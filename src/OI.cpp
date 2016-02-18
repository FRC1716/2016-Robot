#include "OI.h"

#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/PlayerDrive.h"
#include "Commands/Def1.h"
#include "Commands/Def2.h"
#include "Commands/Def3.h"
#include "Commands/Def4.h"
#include "Commands/Def5.h"
#include "Commands/Def6.h"
#include "Commands/Def7.h"
#include "Commands/Def8.h"
#include "Commands/Def9.h"
#include "Commands/Pos1.h"
#include "Commands/Pos2.h"
#include "Commands/Pos3.h"
#include "Commands/Pos4.h"
#include "Commands/Pos5.h"
#include "Commands/WindowForward.h"
#include "Commands/WindowReverse.h"


OI::OI() {
    // Process operator interface input here.
    rightJoystick.reset(new Joystick(1));
    
    leftJoystick.reset(new Joystick(0));

    windowReverseB.reset(new JoystickButton(leftJoystick.get(), 1));
    windowReverseB->WhileHeld(new WindowReverse());
    windowForwardB.reset(new JoystickButton(leftJoystick.get(), 1));
    windowForwardB->WhileHeld(new WindowForward());

    // SmartDashboard Buttons
    /*
    SmartDashboard::PutData("WindowReverse", new WindowReverse());
    SmartDashboard::PutData("WindowForward", new WindowForward());
    SmartDashboard::PutData("DriveC", new DriveC());
    SmartDashboard::PutData("Pos5", new Pos5());
    SmartDashboard::PutData("Pos4", new Pos4());
    SmartDashboard::PutData("Pos3", new Pos3());
    SmartDashboard::PutData("Pos2", new Pos2());
    SmartDashboard::PutData("Pos1", new Pos1());
    SmartDashboard::PutData("Def9", new Def9());
    SmartDashboard::PutData("Def8", new Def8());
    SmartDashboard::PutData("Def7", new Def7());
    SmartDashboard::PutData("Def6", new Def6());
    SmartDashboard::PutData("Def5", new Def5());
    SmartDashboard::PutData("Def4", new Def4());
    SmartDashboard::PutData("Def3", new Def3());
    SmartDashboard::PutData("Def2", new Def2());
    SmartDashboard::PutData("Def1", new Def1());
    */
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());
    SmartDashboard::PutData("Player Drive", new PlayerDrive());

    SmartDashboard::PutNumber("Position", Robot::controlSS->posNum);
    SmartDashboard::PutNumber("Defense", Robot::controlSS->defNum);
    SmartDashboard::PutNumber("Arm PSI", Robot::controlSS->armPSI);
    SmartDashboard::PutNumber("Shooter PSI", Robot::controlSS->shooterPSI);
}

std::shared_ptr<Joystick> OI::getLeftJoystick() {
   return leftJoystick;
}

std::shared_ptr<Joystick> OI::getRightJoystick() {
   return rightJoystick;
}

