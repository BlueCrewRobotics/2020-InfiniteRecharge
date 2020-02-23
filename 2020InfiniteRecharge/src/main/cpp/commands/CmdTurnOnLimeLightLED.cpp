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

#include "commands/CmdTurnOnLimeLightLED.h"

#include "Robot.h"

CmdTurnOnLimeLightLED::CmdTurnOnLimeLightLED() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void CmdTurnOnLimeLightLED::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdTurnOnLimeLightLED::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool CmdTurnOnLimeLightLED::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdTurnOnLimeLightLED::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdTurnOnLimeLightLED::Interrupted() {}
