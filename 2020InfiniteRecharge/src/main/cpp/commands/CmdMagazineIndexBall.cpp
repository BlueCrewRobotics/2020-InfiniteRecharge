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
  breakSensorLock = 0;
}

// Called repeatedly when this Command is scheduled to run
void CmdMagazineIndexBall::Execute() {
  if(breakSensorLock == 0) {
        // Indexes ball into Magazine
    if(Robot::m_subMagazine.ballCount < 3) {
      Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 1);
    } else if (Robot::m_subMagazine.ballCount == 3) {
      Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 0.5);
    }
    
    // Increases ballCount if ball count is less than 4(So we dont have more than 4 balls in the intake)
    if(Robot::m_subMagazine.ballCount <= 4) {
      Robot::m_subMagazine.ballCount = Robot::m_subMagazine.ballCount + 1;  
      breakSensorLock = 1;
    }
  } else {
    if(Robot::m_subMagazine.ballCount == 4) {
      isFinished = 1;
    } else if (Robot::m_subMagazine.ballCount < 4) {

    
    velocity = Robot::m_subMagazine.GetMotorVelocity();
  if (velocity <= 5 && velocity >= -5) {
    isMoving = false;
  } else {
    isMoving = true;
  }

  if(Robot::m_subMagazine.sensors[0] == true && isMoving == false) {
    Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 0.1);
  } else if(Robot::m_subMagazine.sensors[0] == false && isMoving == false) {
    isFinished = 1;
  }

  }
  }
    
}

// Make this return true when this Command no longer needs to run execute()
bool CmdMagazineIndexBall::IsFinished() { 
  return isFinished;


  }

// Called once after isFinished returns true
void CmdMagazineIndexBall::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdMagazineIndexBall::Interrupted() {}
