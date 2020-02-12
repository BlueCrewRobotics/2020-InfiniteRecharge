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

#include "subsystems/SubMagazine.h"

#include "RobotMap.h"

SubMagazine::SubMagazine() : frc::Subsystem("SubMagazine") {}

void SubMagazine::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void SubMagazine::MoveForward(int blocks) {

}

void SubMagazine::MoveBackward(int blocks) {

}

bool SubMagazine::GetBreakSwitch() {
  currentSwitchState = m_intakeSwitch->GetSwitchState();
  return currentSwitchState;
}

int SubMagazine::GetBallCount() {

}
// Put methods for controlling this subsystem
// here. Call these from Commands.
