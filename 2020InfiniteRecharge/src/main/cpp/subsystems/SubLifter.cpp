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

    double kP = 0.1, kI = 1e-4, kD = 1, kIz = 0, kFF = 0, kMaxOutput = 1, kMinOutput = -1;

    //lifterEngageMotor.RestoreFactoryDefaults();
    
    // set PID coefficients
    pidController.SetP(kP);
    pidController.SetI(kI);
    pidController.SetD(kD);
    pidController.SetIZone(kIz);
    pidController.SetFF(kFF);
    pidController.SetOutputRange(kMinOutput, kMaxOutput);
}

void SubLifter::EngageLifter() {
    pidController.SetReference(10, rev::ControlType::kPosition); // 1 is rotations
    lifterEngageMotor.Set(-0.1);
}

void SubLifter::LifterUp() {

}

void SubLifter::LifterDown() {

}

void SubLifter::DisengageLifter() {
    pidController.SetReference(0, rev::ControlType::kPosition, ); // 1 is rotations
    //lifterEngageMotor.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
