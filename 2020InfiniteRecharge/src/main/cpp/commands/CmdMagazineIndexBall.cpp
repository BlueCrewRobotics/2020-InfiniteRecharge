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

#include "commands/CmdMagazineIndexBall.h"

#include "Robot.h"

CmdMagazineIndexBall::CmdMagazineIndexBall() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subMagazine);
}

// Called just before this Command runs the first time
void CmdMagazineIndexBall::Initialize() {
  isFinished = 0;
}

// Called repeatedly when this Command is scheduled to run
void CmdMagazineIndexBall::Execute() {
 
        // Indexes ball into Magazine
    if(Robot::m_subMagazine.GetBallCount() < 3) {
      Robot::m_subMagazine.MoveToPosition(-6000);
      if(Robot::m_subMagazine.GetBallCount() != 4  ) {
        Robot::m_subMagazine.IncreaseBallCount(1);
      }
    } else if (Robot::m_subMagazine.GetBallCount() == 3) {
      Robot::m_subMagazine.MoveToPosition(-3000);
      if(Robot::m_subMagazine.GetBallCount() != 4  ) {
        Robot::m_subMagazine.IncreaseBallCount(1);
      }
    }
}

// Make this return true when this Command no longer needs to run execute()
bool CmdMagazineIndexBall::IsFinished() { 
  return true;


  }

// Called once after isFinished returns true
void CmdMagazineIndexBall::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdMagazineIndexBall::Interrupted() {}
