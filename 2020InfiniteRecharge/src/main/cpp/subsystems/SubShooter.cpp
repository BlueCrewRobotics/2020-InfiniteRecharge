/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubShooter.h"

#include "RobotMap.h"

SubShooter::SubShooter() : frc::Subsystem("SubShooter") {}

void SubShooter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void SubShooter::Shoot(double topSpeed, double bottomSpeed) {
  // This might need to be changed on the final robot
 
  topShooterMotor->Set(ControlMode::PercentOutput, topSpeed);
  bottomShooterMotor->Set(ControlMode::PercentOutput, bottomSpeed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
