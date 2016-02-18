#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"


std::shared_ptr<SpeedController> RobotMap::driveSubsystemLeftControl;
std::shared_ptr<Encoder> RobotMap::driveSubsystemLeftEncoder;
std::shared_ptr<PIDController> RobotMap::driveSubsystemLeftDrive;
std::shared_ptr<Encoder> RobotMap::driveSubsystemRightEncoder;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemRightControl;
std::shared_ptr<PIDController> RobotMap::driveSubsystemRightDrive;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemRearLeft;
std::shared_ptr<SpeedController> RobotMap::driveSubsystemRearRight;
std::shared_ptr<RobotDrive> RobotMap::driveSubsystemBackDrive;
std::shared_ptr<AnalogInput> RobotMap::controlSSshooterGauge;
std::shared_ptr<AnalogInput> RobotMap::controlSSarmGauge;


void RobotMap::init() {
    LiveWindow *lw = LiveWindow::GetInstance();

    driveSubsystemLeftControl.reset(new Talon(0));
    lw->AddActuator("Drive Subsystem", "Left Control", (Talon&) driveSubsystemLeftControl);
    
    driveSubsystemLeftEncoder.reset(new Encoder(0, 1, false, Encoder::k4X));
    lw->AddSensor("Drive Subsystem", "Left Encoder", driveSubsystemLeftEncoder);
    driveSubsystemLeftEncoder->SetDistancePerPulse(1.0);
    driveSubsystemLeftEncoder->SetPIDSourceType(PIDSourceType::kRate);

    driveSubsystemLeftDrive.reset(new PIDController(1.0, 0.0, 0.0,/* F: 0.0, */ driveSubsystemLeftEncoder.get(), driveSubsystemLeftControl.get(), 0.02));
    lw->AddActuator("Drive Subsystem", "Left Drive", driveSubsystemLeftDrive);
    driveSubsystemLeftDrive->SetContinuous(false); driveSubsystemLeftDrive->SetAbsoluteTolerance(0.2); 
        driveSubsystemLeftDrive->SetOutputRange(-1.0, 1.0);

    driveSubsystemRightEncoder.reset(new Encoder(2, 3, false, Encoder::k4X));
    lw->AddSensor("Drive Subsystem", "Right Encoder", driveSubsystemRightEncoder);
    driveSubsystemRightEncoder->SetDistancePerPulse(1.0);
    driveSubsystemRightEncoder->SetPIDSourceType(PIDSourceType::kDisplacement);

    driveSubsystemRightControl.reset(new Talon(2));
    lw->AddActuator("Drive Subsystem", "Right Control", (Talon&) driveSubsystemRightControl);
    
    driveSubsystemRightDrive.reset(new PIDController(1.0, 0.0, 0.0,/* F: 0.0, */ driveSubsystemRightEncoder.get(), driveSubsystemRightControl.get(), 0.02));
    lw->AddActuator("Drive Subsystem", "Right Drive", driveSubsystemRightDrive);
    driveSubsystemRightDrive->SetContinuous(false); driveSubsystemRightDrive->SetAbsoluteTolerance(0.2); 
        driveSubsystemRightDrive->SetOutputRange(-1.0, 1.0);

    driveSubsystemRearLeft.reset(new Talon(1));
    lw->AddActuator("Drive Subsystem", "Rear Left", (Talon&) driveSubsystemRearLeft);
    
    driveSubsystemRearRight.reset(new Talon(3));
    lw->AddActuator("Drive Subsystem", "Rear Right", (Talon&) driveSubsystemRearRight);
    
    driveSubsystemBackDrive.reset(new RobotDrive(driveSubsystemRearLeft, driveSubsystemRearRight));
    
    driveSubsystemBackDrive->SetSafetyEnabled(true);
        driveSubsystemBackDrive->SetExpiration(0.1);
        driveSubsystemBackDrive->SetSensitivity(0.5);
        driveSubsystemBackDrive->SetMaxOutput(1.0);

    windowMotor.reset(new VictorSP(5));
    lw->AddActuator("ControlSS", "Intake", (VictorSP&) windowMotor);

    controlSSshooterGauge.reset(new AnalogInput(0));
    lw->AddSensor("ControlSS", "shooterGauge", controlSSshooterGauge);

    controlSSarmGauge.reset(new AnalogInput(1));
    lw->AddSensor("ControlSS", "armGauge", controlSSarmGauge);
}
