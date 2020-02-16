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

#include "commands/CmdColorSpin.h"
#include <frc/DriverStation.h>

#include "Robot.h"

CmdColorSpin::CmdColorSpin() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subColorWheel);
}

// Called just before this Command runs the first time
void CmdColorSpin::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdColorSpin::Execute() {
std::string gameData;
gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
if(gameData.length() > 0)
{
  switch (gameData[0])
  {
    case 'B' :
    if (Robot::m_subColorWheel.ColorMatch != WHEEL_RED)
      Robot::m_subColorWheel.RunColor(.5);
      //Blue case code
      break;
    case 'G' :
    if (Robot::m_subColorWheel.ColorMatch != WHEEL_YELLOW)
      Robot::m_subColorWheel.RunColor(.5);
      //Green case code
      break;
    case 'R' :
    if (Robot::m_subColorWheel.ColorMatch != WHEEL_BLUE)
      Robot::m_subColorWheel.RunColor(.5);
      //Red case code
      break;
    case 'Y' :
    if (Robot::m_subColorWheel.ColorMatch != WHEEL_GREEN)
      Robot::m_subColorWheel.RunColor(.5);
      //Yellow case code
      break;
    default :
      //This is corrupt data
      break;
  }
} else {
  //Code for no data received yet
}
}

// Make this return true when this Command no longer needs to run execute()
bool CmdColorSpin::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdColorSpin::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdColorSpin::Interrupted() {}
