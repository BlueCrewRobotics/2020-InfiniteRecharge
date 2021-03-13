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

#include "commands/CmdJogBall.h"

#include "Robot.h"

CmdJogBall::CmdJogBall() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subMagazine);
}

// Called just before this Command runs the first time
void CmdJogBall::Initialize() {
  
  isFinished = false;
}

// Called repeatedly when this Command is scheduled to run
void CmdJogBall::Execute() {
  //error = Robot::m_subMagazine.GetMotorError();
  //if (error <= 50 && error >= -50) {
  //  isMoving = false;
  //} else {
  //  isMoving = true;
  //}

  //if (isMoving == true) {
    // do nothing
  //} else if (isMoving == false) {
  //  if (Robot::m_subMagazine.GetBallCount() <= 3) {
      if(Robot::m_subMagazine.GetSensor() == false) {
        Robot::m_subMagazine.Jog(-1000);
      } else {
        isFinished = true;
      }
    //} else {
      // Do nothing
    //}
  //}
}

// Make this return true when this Command no longer needs to run execute()
bool CmdJogBall::IsFinished() { 
  return isFinished; 
  }

// Called once after isFinished returns true
void CmdJogBall::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdJogBall::Interrupted() {}
