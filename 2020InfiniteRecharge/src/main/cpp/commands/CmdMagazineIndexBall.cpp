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
void CmdMagazineIndexBall::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMagazineIndexBall::Execute() {
    // Indexes ball into Magazine
    Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 1);
    // Increases ballCount if ball count is less than 4(So we dont have more than 4 balls in the intake)
    if(Robot::m_subMagazine.ballCount <= 4) {
      Robot::m_subMagazine.ballCount = Robot::m_subMagazine.ballCount + 1;  
    }
    
}

// Make this return true when this Command no longer needs to run execute()
bool CmdMagazineIndexBall::IsFinished() { return true; }

// Called once after isFinished returns true
void CmdMagazineIndexBall::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdMagazineIndexBall::Interrupted() {}
