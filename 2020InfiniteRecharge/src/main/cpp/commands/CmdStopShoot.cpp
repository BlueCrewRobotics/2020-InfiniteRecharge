/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CmdStopShoot.h"
#include "subsystems/SubShooter.h"
#include "Robot.h"

CmdStopShoot::CmdStopShoot() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subShooter);
}

// Called just before this Command runs the first time
void CmdStopShoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdStopShoot::Execute() {
    Robot::m_subShooter.Shoot(0, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdStopShoot::IsFinished() { 
    return false;
    
     }

// Called once after isFinished returns true
void CmdStopShoot::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdStopShoot::Interrupted() {}
