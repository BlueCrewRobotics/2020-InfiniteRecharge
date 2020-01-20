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

#include "commands/CmdSwitchGear.h"

#include "Robot.h"

CmdSwitchGear::CmdSwitchGear() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void CmdSwitchGear::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdSwitchGear::Execute() {
  bool lGear = 0;
  bool rGear = 0;
  lGear = Robot::m_subDriveTrain.leftDriveMotor->GetGear();
  rGear = Robot::m_subDriveTrain.rightDriveMotor->GetGear();

  lGear = !lGear;
  rGear = !rGear;

  Robot::m_subDriveTrain.leftDriveMotor->SetGear(lGear);
  Robot::m_subDriveTrain.rightDriveMotor->SetGear(rGear);

  Robot::m_subPCM.ptr_GearSolenoid->Set(lGear);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdSwitchGear::IsFinished() { return true; }

// Called once after isFinished returns true
void CmdSwitchGear::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdSwitchGear::Interrupted() {}
