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

#include "commands/CmdIntake.h"
#include "subsystems/SubIntake.h"

#include "Robot.h"

CmdIntake::CmdIntake() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subIntake);
}

// Called just before this Command runs the first time
void CmdIntake::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdIntake::Execute() {
  if (Robot::m_subMagazine.intakeLock == false) {
    Robot::m_subIntake.RunIntake(.5);
    Robot::m_subMagazine.intakeShootMode = 0;
  }
  
  //Runs
}

// Make this return true when this Command no longer needs to run execute()
bool CmdIntake::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdIntake::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdIntake::Interrupted() {}
