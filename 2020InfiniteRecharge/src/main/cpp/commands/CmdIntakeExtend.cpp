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

#include "commands/CmdIntakeExtend.h"

#include "Robot.h"

CmdIntakeExtend::CmdIntakeExtend() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subIntake);
}

// Called just before this Command runs the first time
void CmdIntakeExtend::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdIntakeExtend::Execute() {
  if (Robot::m_subMagazine.intakeLock == false) {
    Robot::m_subIntake.ExtendIntake9(true);
    Robot::m_subIntake.ExtendIntake1(true);
  }
    //This is for if we have two Solenoids 
}
// Make this return true when this Command no longer needs to run execute()
bool CmdIntakeExtend::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdIntakeExtend::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdIntakeExtend::Interrupted() {}
