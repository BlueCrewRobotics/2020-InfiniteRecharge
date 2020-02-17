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
    if (ballCount = 4) {
      Robot::m_subMagazine.intakeLock = true;
    } else {
      Robot::m_subMagazine.intakeLock = false;
    }
  


  if (Robot::m_subMagazine.intakeShootMode == 0) {
    
    // Put code here for shooter to intake mode switch
    if (Robot::m_subMagazine.intakeShootModeLock == true) {
      if (Robot::m_subMagazine.sensors[1] == true) {
        // do nothing
      } else if (Robot::m_subMagazine.sensors[2] == true) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition - 1);
      } else if (Robot::m_subMagazine.sensors[3] == true) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition - 2);
      } else {
        // do nothing
      }


      Robot::m_subMagazine.intakeShootModeLock = false;
    }

    if (Robot::m_subMagazine.sensors[0] == true) {
      if (ballCount == 0) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 1);
      } else if (ballCount == 1) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 1);
      } else if (ballCount == 2) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 1);
      } else if (ballCount == 3) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 1);
      } /*else if (ballCount == 4) {
        Robot::m_subMagazine.intakeLock = true; 
      }*/
    }

  } else if (Robot::m_subMagazine.intakeShootMode == 1) {

    if (Robot::m_subMagazine.intakeShootModeLock == false) {
      Robot::m_subMagazine.MoveToPosition(4);
      Robot::m_subMagazine.intakeShootModeLock = true;

    } else if (Robot::m_subMagazine.ballsShot == 1 && ballCount != 0) {
      Robot::m_subMagazine.MoveToPosition(5);

    } else if (Robot::m_subMagazine.ballsShot == 2 && ballCount != 0) {
      Robot::m_subMagazine.MoveToPosition(6);

    } else if (Robot::m_subMagazine.ballsShot >= 3 && ballCount != 0) {
      Robot::m_subMagazine.MoveToPosition(7);
      }
      

      if (Robot::m_subMagazine.sensors[1] == false && Robot::m_subMagazine.sensors[2] == false && Robot::m_subMagazine.sensors[3] == false) {
        Robot::m_subMagazine.ResetEncoderPosition();
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
