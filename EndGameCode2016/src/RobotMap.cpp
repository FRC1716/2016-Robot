// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
/*
std::shared_ptr<RobotDrive> RobotMap::controlSSRobotDrive;
std::shared_ptr<AnalogInput> RobotMap::controlSSshooterGauge;
std::shared_ptr<AnalogInput> RobotMap::controlSSarmGauge;*/
std::shared_ptr<SpeedController> RobotMap::controlSSarm1;
std::shared_ptr<SpeedController> RobotMap::controlSSarm2;
std::shared_ptr<AnalogGyro> RobotMap::controlSSgyro;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemLeftControl;
std::shared_ptr<Encoder> RobotMap::driveSubsystemLeftEncoder;
std::shared_ptr<Encoder> RobotMap::driveSubsystemRightEncoder;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemRightControl;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemRearLeft;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemRearRight;
std::shared_ptr<RobotDrive> RobotMap::driveSubsystemDrive;
/*
std::shared_ptr<DigitalInput> RobotMap::controlSSfrontLS;
std::shared_ptr<DigitalInput> RobotMap::controlSSbackLS;
std::shared_ptr<DigitalInput> RobotMap::controlSSsideLS;
std::shared_ptr<Solenoid> RobotMap::controlSSsolenoid1;
std::shared_ptr<Solenoid> RobotMap::controlSSsolenoid2;
std::shared_ptr<Solenoid> RobotMap::controlSSsolenoid3;
std::shared_ptr<Solenoid> RobotMap::controlSSsolenoid4;
std::shared_ptr<AnalogInput> RobotMap::controlSSpressureGauge;

std::shared_ptr<SpeedController> RobotMap::windowMotor;*/
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    controlSSgyro.reset(new AnalogGyro(0));
    	lw->AddSensor("ControlSS", "Gryo", controlSSgyro);
    	controlSSgyro->SetSensitivity(0.007);

    /*controlSSpressureGauge.reset(new AnalogInput(1));
        lw->AddSensor("ControlSS", "pressureGauge", controlSSpressureGauge);
    */
    controlSSarm1.reset(new VictorSP(4));
    	lw->AddActuator("Subsystem1", "Speed Controller 1", std::static_pointer_cast<VictorSP>(controlSSarm1));

    controlSSarm2.reset(new VictorSP(5));
    	lw->AddActuator("Subsystem1", "Speed Controller 2", std::static_pointer_cast<VictorSP>(controlSSarm2));
/*
    controlSSsolenoid1.reset(new Solenoid(1));
    	lw->AddActuator("ControlSS", "solenoid1", controlSSsolenoid1);

  	controlSSsolenoid2.reset(new Solenoid(2));
        lw->AddActuator("ControlSS", "solenoid2", controlSSsolenoid2);

    controlSSsolenoid3.reset(new Solenoid(3));
        lw->AddActuator("ControlSS", "solenoid3", controlSSsolenoid3);

    controlSSsolenoid4.reset(new Solenoid(4));
        lw->AddActuator("ControlSS", "solenoid4", controlSSsolenoid4);

    controlSSfrontLS.reset(new DigitalInput(1));
   	    lw->AddSensor("ControlSS", "frontLS", controlSSfrontLS);

   	controlSSbackLS.reset(new DigitalInput(2));
        lw->AddSensor("ControlSS", "backLS", controlSSbackLS);

    controlSSsideLS.reset(new DigitalInput(3));
    	lw->AddSensor("ControlSS", "sideLS", controlSSsideLS);*/

    driveSubsystemLeftControl.reset(new Talon(0));
        lw->AddActuator("Drive Subsystem", "Left Control", (Talon&) driveSubsystemLeftControl);

    driveSubsystemLeftEncoder.reset(new Encoder(0, 1, false, Encoder::k4X));
        lw->AddSensor("Drive Subsystem", "Left Encoder", driveSubsystemLeftEncoder);
        driveSubsystemLeftEncoder->SetDistancePerPulse(1.0);
        driveSubsystemLeftEncoder->SetPIDSourceType(PIDSourceType::kRate);

    driveSubsystemRightEncoder.reset(new Encoder(2, 3, false, Encoder::k4X));
        lw->AddSensor("Drive Subsystem", "Right Encoder", driveSubsystemRightEncoder);
        driveSubsystemRightEncoder->SetDistancePerPulse(1.0);
        driveSubsystemRightEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);

    driveSubsystemRightControl.reset(new Talon(2));
        lw->AddActuator("Drive Subsystem", "Right Control", (Talon&) driveSubsystemRightControl);

    driveSubsystemRearLeft.reset(new Talon(1));
        lw->AddActuator("Drive Subsystem", "Rear Left", (Talon&) driveSubsystemRearLeft);

    driveSubsystemRearRight.reset(new Talon(3));
        lw->AddActuator("Drive Subsystem", "Rear Right", (Talon&) driveSubsystemRearRight);

    driveSubsystemDrive.reset(new RobotDrive(driveSubsystemLeftControl, driveSubsystemRearLeft, driveSubsystemRightControl, driveSubsystemRearRight));
        driveSubsystemDrive->SetSafetyEnabled(true);
        driveSubsystemDrive->SetExpiration(0.1);
        driveSubsystemDrive->SetSensitivity(0.5);
        driveSubsystemDrive->SetMaxOutput(1.0);

        /*
    windowMotor.reset(new VictorSP(6));
        lw->AddActuator("ControlSS", "Intake", (VictorSP&) windowMotor);
        */


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
