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

#include "subsystems/SubIntake.h"

#include "RobotMap.h"

SubIntake::SubIntake() : frc::Subsystem("SubIntake") {}

void SubIntake::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Extends and retracts piston on intake
void SubIntake::ExtendIntake(bool Extention) {
  extendSolenoid->Set(Extention);
}

// Runs intake motor
void SubIntake::RunIntake(double Speed) {
  Speed = Speed * -1;
  intakeMotor->Set(ControlMode::PercentOutput, Speed);

}


// Put methods for controlling this subsystem
// here. Call these from Commands.
