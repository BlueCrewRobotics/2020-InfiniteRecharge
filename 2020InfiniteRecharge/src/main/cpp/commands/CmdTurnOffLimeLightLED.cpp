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

#include "commands/CmdTurnOffLimeLightLED.h"

#include "Robot.h"

CmdTurnOffLimeLightLED::CmdTurnOffLimeLightLED() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void CmdTurnOffLimeLightLED::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdTurnOffLimeLightLED::Execute() {
  Robot::m_subLimelight.SetLEDState(1);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdTurnOffLimeLightLED::IsFinished() { return true; }

// Called once after isFinished returns true
void CmdTurnOffLimeLightLED::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdTurnOffLimeLightLED::Interrupted() {}
