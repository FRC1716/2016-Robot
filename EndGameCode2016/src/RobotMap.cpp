#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"

std::shared_ptr<SpeedController> RobotMap::controlSSarmAngle1;
std::shared_ptr<SpeedController> RobotMap::controlSSarmAngle2;
std::shared_ptr<SpeedController> RobotMap::controlSSarmExtend1;
std::shared_ptr<AnalogGyro> RobotMap::controlSSgyro;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemLeftControl;
std::shared_ptr<Encoder> RobotMap::driveSubsystemLeftEncoder;
std::shared_ptr<Encoder> RobotMap::driveSubsystemRightEncoder;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemRightControl;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemRearLeft;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemRearRight;
std::shared_ptr<RobotDrive> RobotMap::driveSubsystemDrive;
std::shared_ptr<DigitalInput> RobotMap::controlSSfrontLS;
std::shared_ptr<DigitalInput> RobotMap::controlSSbackLS;
std::shared_ptr<DigitalInput> RobotMap::controlSSsideLS;
std::shared_ptr<Solenoid> RobotMap::controlSSsolenoid0;
std::shared_ptr<Solenoid> RobotMap::controlSSsolenoid1;
std::shared_ptr<Solenoid> RobotMap::controlSSsolenoid2;
std::shared_ptr<Solenoid> RobotMap::controlSSsolenoid3;
std::shared_ptr<AnalogInput> RobotMap::controlSSpressureGauge;
std::shared_ptr<SpeedController> RobotMap::controlSSintake;

void RobotMap::init() {
    LiveWindow *lw = LiveWindow::GetInstance();

    controlSSgyro.reset(new AnalogGyro(0));
    	lw->AddSensor("ControlSS", "Gyro", controlSSgyro);
    	controlSSgyro->SetSensitivity(0.007);

    controlSSpressureGauge.reset(new AnalogInput(1));
        lw->AddSensor("ControlSS", "pressureGauge", controlSSpressureGauge);

    controlSSarmAngle1.reset(new VictorSP(4));
    	lw->AddActuator("ControlSS", "controlSSarmAngle1", std::static_pointer_cast<VictorSP>(controlSSarmAngle1));

    controlSSarmAngle2.reset(new VictorSP(5));
    	lw->AddActuator("ControlSS", "controlSSarmAngle2", std::static_pointer_cast<VictorSP>(controlSSarmAngle2));

    controlSSarmExtend1.reset(new VictorSP(6));
    	lw->AddActuator("ControlSS", "controlSSarmExtend1", std::static_pointer_cast<VictorSP>(controlSSarmExtend1));

    controlSSsolenoid0.reset(new Solenoid(0));
    	lw->AddActuator("ControlSS", "solenoid0", controlSSsolenoid0);

  	controlSSsolenoid1.reset(new Solenoid(1));
        lw->AddActuator("ControlSS", "solenoid1", controlSSsolenoid1);

    controlSSsolenoid2.reset(new Solenoid(2));
        lw->AddActuator("ControlSS", "solenoid2", controlSSsolenoid2);

    controlSSsolenoid3.reset(new Solenoid(3));
        lw->AddActuator("ControlSS", "solenoid3", controlSSsolenoid3);

    controlSSfrontLS.reset(new DigitalInput(4));
   	    lw->AddSensor("ControlSS", "frontLS", controlSSfrontLS);

   	controlSSbackLS.reset(new DigitalInput(5));
        lw->AddSensor("ControlSS", "backLS", controlSSbackLS);

    controlSSsideLS.reset(new DigitalInput(6));
    	lw->AddSensor("ControlSS", "sideLS", controlSSsideLS);

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


    controlSSintake.reset(new VictorSP(6));
        lw->AddActuator("IntakeSubsystem", "Speed Controller 1", std::static_pointer_cast<VictorSP>(controlSSintake));
}
