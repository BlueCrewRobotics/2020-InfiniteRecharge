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

#include "autocommands/AutoCmdTurn.h"

#include "Robot.h"
#include "subsystems/SubDriveTrain.h"

AutoCmdTurn::AutoCmdTurn(int autoType) {
  // Use Requires() here to declare subsystem dependencies
  this->m_iautoType = autoType;
  Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void AutoCmdTurn::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoCmdTurn::Execute() {
  if (m_iautoType == 0) {
    Robot::m_subDriveTrain.AutoDrive(-5, 5);
  }
  
  
    
}

// Make this return true when this Command no longer needs to run execute()o[]
bool AutoCmdTurn::IsFinished() { return true; }

// Called once after isFinished returns true
void AutoCmdTurn::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCmdTurn::Interrupted() {}
