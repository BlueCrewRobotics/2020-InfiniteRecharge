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

void SubIntake::ExtendIntake1(bool Extention) {
  extendSolenoid->Set(Extention);
}
void SubIntake::ExtendIntake9(bool Extention) {
  extendSolenoid->Set(Extention);
}
//Remove on if these if we only use one Solenoid

void SubIntake::RunIntake(double Speed) {
  intakeMotor->Set(ControlMode::PercentOutput, Speed);

}


// Put methods for controlling this subsystem
// here. Call these from Commands.
