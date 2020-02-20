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
  
  // Gets the velocity of the magazine motor to check if its moving
  velocity = Robot::m_subMagazine.GetMotorVelocity();
  if (velocity <= 5 && velocity >= -5) {
    isMoving = false;
  } else {
    isMoving = true;
  }

  // This is so nothing runs in this command unless the magazine isn't moving
  if (isMoving == false) {
    // Updates sensors and gets ball count for future use
    Robot::m_subMagazine.UpdateSensors();
    ballCount = Robot::m_subMagazine.GetBallCount();

    // Stops the intake from running when we have max balls
    if (ballCount = 4) {
      Robot::m_subMagazine.intakeLock = true;
    } else {
      Robot::m_subMagazine.intakeLock = false;
    }
  

  // if in intake mode:
  if (Robot::m_subMagazine.intakeShootMode == 0) {
    
    // Code for when the mode switches to intake mode
    // intakeShootModeLock is to prevent this if statement to run more than once when in intake mode
    if (Robot::m_subMagazine.intakeShootModeLock == true) {

      // These if statements move the balls to the front of the robot so we can index balls
      if (Robot::m_subMagazine.sensors[1] == true) {
        // do nothing
      } else if (Robot::m_subMagazine.sensors[2] == true) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition - 1);
      } else if (Robot::m_subMagazine.sensors[3] == true) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition - 2);
      } else if (Robot::m_subMagazine.sensors[4] == true){
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition - 3);
      }
      // Switches intakeShootModeLock to false so this isn't run again
      Robot::m_subMagazine.intakeShootModeLock = false;
    }

    // Checks to see if there is a ball coming into the magazine and indexes it
    if (Robot::m_subMagazine.sensors[0] == true) {
      if (ballCount < 4) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 1);
      }
    }

    // if in shoot mode:
  } else if (Robot::m_subMagazine.intakeShootMode == 1) {

    // Code for when the mode switches to shoot mode
    // intakeShootModeLock is to prevent this if statement to run more than once when in shoot mode
    // This moves all balls in the magazine to the correct position to fire
    if (Robot::m_subMagazine.intakeShootModeLock == false) {
      if (Robot::m_subMagazine.sensors[4] == true) {
        // do nothing
      } else if (Robot::m_subMagazine.sensors[3] == true) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 1);
      } else if (Robot::m_subMagazine.sensors[2] == true) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 2);
      } else if (Robot::m_subMagazine.sensors[1] == true) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 3);
      }
      Robot::m_subMagazine.intakeShootModeLock = true;
    }
      // if the x button is pressed shoot a ball(This will change later so that it wont shoot unless targeting has finished)
      if(Robot::m_oi.driverController_button_x->Get() == 1) {
        Robot::m_subMagazine.MoveToPosition(Robot::m_subMagazine.currentPosition + 1);
      }

  }
    // if belt is clear reset encoder value to 0
    if (Robot::m_subMagazine.sensors[1] == false && Robot::m_subMagazine.sensors[2] == false && Robot::m_subMagazine.sensors[3] == false && Robot::m_subMagazine.sensors[4] == false) {
    Robot::m_subMagazine.ResetEncoderPosition();
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
