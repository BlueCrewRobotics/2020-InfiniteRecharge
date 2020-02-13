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

#include "commands/CmdNumberSpin.h"

#include "Robot.h"
#include <iostream>
using namespace std;

CmdNumberSpin::CmdNumberSpin() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subColorWheel);
}

// Called just before this Command runs the first time
void CmdNumberSpin::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdNumberSpin::Execute() {
Robot::m_subColorWheel.ColorMatch = Robot::m_subColorWheel.GetColorMatch();
if (Robot::m_subColorWheel.Lock == false) {

  std::cout << Robot::m_subColorWheel.ColorMatch << std::endl;
  
  if (Robot::m_subColorWheel.ColorLock == false) {
    if (Robot::m_subColorWheel.ColorMatch == 0){
      //0 = Blue
      Robot::m_subColorWheel.ColorLock = true;

    }
  }
  if (Robot::m_subColorWheel.ColorLock == true){
      if (Robot::m_subColorWheel.ColorMatch == 1){
      //1 = Green
      Robot::m_subColorWheel.ColorLock = true;
      Robot::m_subColorWheel.counter++;
      }
  }
  if (Robot::m_subColorWheel.counter == 8){
    Robot::m_subColorWheel.Lock = true;
  }
}
}

// Make this return true when this Command no longer needs to run execute()
bool CmdNumberSpin::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdNumberSpin::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdNumberSpin::Interrupted() {}
