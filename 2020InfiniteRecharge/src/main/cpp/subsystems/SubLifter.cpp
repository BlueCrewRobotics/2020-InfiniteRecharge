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
    double kMaxOutput = 0.4;
    double kMinOutput = -0.4;

    //lifterEngageMotor.RestoreFactoryDefaults();
    // set PID coefficients
    //lifterEngageMotor.SetClosedLoopRampRate(1);
    pidController.SetP(kP);
    pidController.SetI(kI);
    pidController.SetD(kD);
    pidController.SetIZone(kIz);
    pidController.SetFF(kFF);
    pidController.SetOutputRange(kMinOutput, kMaxOutput);
}

void SubLifter::EngageLifter() {
    pidController.SetReference(-200, rev::ControlType::kPosition); // THIS NEED TO GO OVER -260
    //lifterEngageMotor.Set(0.1);
}

void SubLifter::LifterUp() {

}

void SubLifter::LifterDown() {

}

void SubLifter::DisengageLifter() {
    pidController.SetReference(3, rev::ControlType::kPosition); // 1 is rotations
    //lifterEngageMotor.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
