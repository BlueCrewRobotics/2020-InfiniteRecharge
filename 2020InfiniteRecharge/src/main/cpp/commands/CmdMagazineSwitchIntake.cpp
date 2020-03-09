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

#include "commands/CmdMagazineSwitchIntake.h"

#include "Robot.h"

CmdMagazineSwitchIntake::CmdMagazineSwitchIntake() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subMagazine);
}

// Called just before this Command runs the first time
void CmdMagazineSwitchIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMagazineSwitchIntake::Execute() {
  // Depending on the ball count it moves the balls from shooting mode to the front of the magazine so another ball can be indexed
        if (Robot::m_subMagazine.GetBallCount() == 4) {
        // do nothing
      } else if (Robot::m_subMagazine.GetBallCount() == 3) {
        Robot::m_subMagazine.MoveToPosition(-6000);
      } else if (Robot::m_subMagazine.GetBallCount() == 2) {
        Robot::m_subMagazine.MoveToPosition(-12000);
      } else if (Robot::m_subMagazine.GetBallCount() == 1){
        Robot::m_subMagazine.MoveToPosition(-18000);
      }
}

// Make this return true when this Command no longer needs to run execute()
bool CmdMagazineSwitchIntake::IsFinished() { return true; }

// Called once after isFinished returns true
void CmdMagazineSwitchIntake::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdMagazineSwitchIntake::Interrupted() {}
