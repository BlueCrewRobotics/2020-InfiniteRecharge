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

#include "commands/CmdTurretToHomePos.h"
#include "subsystems/SubShooter.h"
#include "Robot.h"

CmdTurretToHomePos::CmdTurretToHomePos() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subShooter);
}

// Called just before this Command runs the first time
void CmdTurretToHomePos::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdTurretToHomePos::Execute() {
  Robot::m_subShooter.RotateTurret(0);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdTurretToHomePos::IsFinished() { 
    if(-10 < Robot::m_subShooter.GetTurretLocation() < 10){
      return true;
    }
    return false;
    
}

// Called once after isFinished returns true
void CmdTurretToHomePos::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdTurretToHomePos::Interrupted() {}
