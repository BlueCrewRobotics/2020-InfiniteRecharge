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
void CmdNumberSpin::Initialize() {
  
  // Sets Lock to false and counter to 0 so that this command can function again if something happens
  Robot::m_subColorWheel.Lock = false;
  Robot::m_subColorWheel.counter = 0;
}

// Called repeatedly when this Command is scheduled to run
void CmdNumberSpin::Execute() {

// Gets the color detected from the sensor
Robot::m_subColorWheel.ColorMatch = Robot::m_subColorWheel.GetColorMatch();

// This if statement locks this system if it is Lock is turned to true
if (Robot::m_subColorWheel.Lock == false) {

  // Prints out the color for debugging purposes
  std::cout << Robot::m_subColorWheel.ColorMatch << std::endl;
  
  // This if statement interlocks between the blue color and the green color after they have been detected
  if (Robot::m_subColorWheel.ColorLock == false) {

    // Tests to see if the color from the sensor is blue(0 is the value of blue)
    if (Robot::m_subColorWheel.ColorMatch == 0){

      // Switches ColorLock to true so this if statement isn't run again
      Robot::m_subColorWheel.ColorLock = true;

    }
    // This if statement interlocks between the blue color and the green color after they have been detected
  } else if (Robot::m_subColorWheel.ColorLock == true){

      // Tests to see if the color from the sensor is green(1 is the value of green)
      if (Robot::m_subColorWheel.ColorMatch == 1){
      
      // Switches ColorLock to true so this if statement isn't run again
      Robot::m_subColorWheel.ColorLock = false;
      // Increases the counter by 1
      Robot::m_subColorWheel.counter++;
      }
  }
  // Checks to see if the counter is at 8
  if (Robot::m_subColorWheel.counter == 8){
    // Changes Lock to true to prevent all previous if statements from running
    Robot::m_subColorWheel.Lock = true;
    
  }
  
}
}

// Make this return true when this Command no longer needs to run execute()
bool CmdNumberSpin::IsFinished() { return false; }

// Called once after isFinished returns true
void CmdNumberSpin::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdNumberSpin::Interrupted() {}
