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

#include "commands/CmdMagazine.h"

#include "Robot.h"

CmdMagazine::CmdMagazine() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subMagazine);
}

// Called just before this Command runs the first time
void CmdMagazine::Initialize() {
  
}

// Called repeatedly when this Command is scheduled to run
void CmdMagazine::Execute() {
  
  velocity = Robot::m_subMagazine.GetMotorVelocity();
  if (velocity <= 5 && velocity >= -5) {
    isMoving = false;
  } else {
    isMoving = true;
  }

  if (isMoving == false) {
    Robot::m_subMagazine.UpdateSensors();
    ballCount = Robot::m_subMagazine.GetBallCount();
  


  if (Robot::m_subMagazine.intakeShootMode == 0) {
    // THIS IS NEEDED IF WE WANT TO TRY FOR 5 BALLS
    /*if (Robot::m_subMagazine.sensors[0] == true && ballCount == 4) {
      Robot::m_subMagazine.MoveToPosition(5);
    }
    */

    if (Robot::m_subMagazine.sensors[0] == true) {
      if (ballCount == 0) {
        Robot::m_subMagazine.MoveToPosition(1);
      } else if (ballCount == 1) {
        Robot::m_subMagazine.MoveToPosition(2);
      } else if (ballCount == 2) {
        Robot::m_subMagazine.MoveToPosition(3);
      } else if (ballCount == 3) {
        Robot::m_subMagazine.MoveToPosition(4);
      } /*else if (ballCount == 4) {
        Robot::m_subMagazine.MoveToPosition(5);
      }*/
    }

  } else if (Robot::m_subMagazine.intakeShootMode == 1) {

    if (Robot::m_subMagazine.ballsShot == 1) {
      


      Robot::m_subMagazine.ballsShot = 0;
    }

    // Move to stage 4 if not already at stage 4
    // When ball is fired move to stage 5 if there is that amount of balls
    // When next ball is fired move to stage 6 if there is that amount of balls
    // When next ball is fired move to stage 7 if there is that amount of balls
    // When ball count = 0 then reset encoder to stage 0
    
    if (ballCount == 1) {
      if (Robot::m_subMagazine.ballsShot == 0) {
      Robot::m_subMagazine.MoveToPosition(4);
    } else if (Robot::m_subMagazine.ballsShot == 1) {
      Robot::m_subMagazine.MoveToPosition(5);
    }

    } else if (ballCount == 2) {

    }
    


  }

  }








}

// Make this return true when this Command no longer needs to run execute()
bool CmdMagazine::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdMagazine::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdMagazine::Interrupted() {}
