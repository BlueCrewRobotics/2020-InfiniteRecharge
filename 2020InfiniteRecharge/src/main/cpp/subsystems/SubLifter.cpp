/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                        Infinite Recharge 2020                              */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubLifter.h"

#include "RobotMap.h"


SubLifter::SubLifter() : frc::Subsystem("SubLifter") {}

void SubLifter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void SubLifter::ConfigureMotors() {

    double kP = 0.05;
    double kI = 0;
    double kD = 0;
    double kIz = 0;
    double kFF = 0;
    double kMaxOutput = 0.6;
    double kMinOutput = -0.6;

    //lifterEngageMotor.RestoreFactoryDefaults();
    // set PID coefficients
    lifterEngageMotor.SetClosedLoopRampRate(0.5);
    pidController.SetP(kP);
    pidController.SetI(kI);
    pidController.SetD(kD);
    pidController.SetIZone(kIz);
    pidController.SetFF(kFF);
    pidController.SetOutputRange(kMinOutput, kMaxOutput);

    climberMotor->ConfigForwardSoftLimitThreshold(0, 0); // 0 is the real value
    climberMotor->ConfigReverseSoftLimitThreshold(-14200, 0); // -14270 is the real value
    climberMotor->ConfigForwardSoftLimitEnable(true, 0);
    climberMotor->ConfigReverseSoftLimitEnable(true, 0);

    climberMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);

    //climberMotor->Config_kF(0,0, 0); 
    //climberMotor->Config_kP(0,0.5, 0); 
    //climberMotor->Config_kI(0,0, 0);
    //climberMotor->Config_kD(0,0, 0); 

    climberMotor->SelectProfileSlot(0, 0);
    climberMotor->ConfigNominalOutputForward(0, 0);
    climberMotor->ConfigNominalOutputReverse(0, 0);
    climberMotor->ConfigPeakOutputForward(1, 0);
    climberMotor->ConfigPeakOutputReverse(-1, 0);




}

void SubLifter::EngageLifter() {
    pidController.SetReference(-260, rev::ControlType::kPosition); // THIS NEED TO GO OVER -260
    //lifterEngageMotor.Set(0.1);
}

void SubLifter::LifterUp() {
    climberMotor->Set(ControlMode::PercentOutput, -0.75);
}

void SubLifter::LifterDown() {
    climberMotor->Set(ControlMode::PercentOutput, 0.75);
}

void SubLifter::LifterStop() {
    climberMotor->Set(ControlMode::PercentOutput, 0);
}

void SubLifter::DisengageLifter() {
    pidController.SetReference(3, rev::ControlType::kPosition); // 1 is rotations
    //lifterEngageMotor.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
