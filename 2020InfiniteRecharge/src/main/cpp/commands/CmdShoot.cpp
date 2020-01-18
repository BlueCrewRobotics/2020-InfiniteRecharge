/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CmdShoot.h"
#include "subsystems/SubShooter.h"
#include "Robot.h"

CmdShoot::CmdShoot() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void CmdShoot::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdShoot::Execute() {
    m_subShooter.Shoot(0.5, 0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdShoot::IsFinished() { 
    return false;
    
     }

// Called once after isFinished returns true
void CmdShoot::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdShoot::Interrupted() {}
