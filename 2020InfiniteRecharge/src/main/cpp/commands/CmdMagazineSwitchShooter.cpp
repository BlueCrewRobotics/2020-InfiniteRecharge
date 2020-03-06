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

#include "commands/CmdMagazineSwitchShooter.h"

#include "Robot.h"

CmdMagazineSwitchShooter::CmdMagazineSwitchShooter() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subMagazine);
}

// Called just before this Command runs the first time
void CmdMagazineSwitchShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMagazineSwitchShooter::Execute() {
  // Moves the balls from their intake position to underneith the shooter to prepare to be indexed into the shooter
        if (Robot::m_subMagazine.GetBallCount() == 4) {
        // do nothing
      } else if (Robot::m_subMagazine.GetBallCount() == 3) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition - 1);
      } else if (Robot::m_subMagazine.GetBallCount() == 2) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition - 2);
      } else if (Robot::m_subMagazine.GetBallCount() == 1) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition - 3);
      }
}

// Make this return true when this Command no longer needs to run execute()
bool CmdMagazineSwitchShooter::IsFinished() { return true; }

// Called once after isFinished returns true
void CmdMagazineSwitchShooter::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdMagazineSwitchShooter::Interrupted() {}
