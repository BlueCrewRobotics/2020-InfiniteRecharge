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

#include "autocommands/AutoCmdShoot.h"

#include "Robot.h"

AutoCmdShoot::AutoCmdShoot() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void AutoCmdShoot::Initialize() {
    SetTimeout(2);
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdShoot::Execute() {
    Robot::m_subMagazine.AddToPosition(Robot::m_subMagazine.currentPosition + 4);

}

// Make this return true when this Command no longer needs to run execute()
bool AutoCmdShoot::IsFinished() { return true; }

// Called once after isFinished returns true
void AutoCmdShoot::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCmdShoot::Interrupted() {}
