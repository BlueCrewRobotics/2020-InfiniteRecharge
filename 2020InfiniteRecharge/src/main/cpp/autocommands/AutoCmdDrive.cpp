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

#include "autocommands/AutoCmdDrive.h"

#include "subsystems/SubDriveTrain.h"

#include "Robot.h"

AutoCmdDrive::AutoCmdDrive() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subDriveTrain);
}

// Called just before this Command runs the first time
void AutoCmdDrive::Initialize() {
  //SetTimeout(3);
}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDrive::Execute() {
    Robot::m_subDriveTrain.AutoDrive(-10, -10);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoCmdDrive::IsFinished() { 
  return false;
  /*
  if (Robot::m_subDriveTrain.GetLeftMotorPosition() >= 40,900 && Robot::m_subDriveTrain.GetLeftMotorPosition() <= 41020) {
    if (Robot::m_subDriveTrain.GetRightMotorPosition() >= 40,900 && Robot::m_subDriveTrain.GetRightMotorPosition() <= 41020) {
      return true;
    }
  } else {
    return false;
  }*/
   }

// Called once after isFinished returns true
void AutoCmdDrive::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCmdDrive::Interrupted() {}
