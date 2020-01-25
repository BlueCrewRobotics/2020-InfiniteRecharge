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

#include "commands/CmdNavRead.h"

#include "Robot.h"

CmdNavRead::CmdNavRead() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subNavX);
}

// Called just before this Command runs the first time
void CmdNavRead::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdNavRead::Execute() {
    Robot::m_subNavX.GetNavValues();
}

// Make this return true when this Command no longer needs to run execute()
bool CmdNavRead::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdNavRead::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdNavRead::Interrupted() {}
