/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*      Ifinite Recharge 2020      */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/SubColorWheel.h"

#include "RobotMap.h"

SubColorWheel::SubColorWheel() : frc::Subsystem("SubColorWheel") {}

void SubColorWheel::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

frc::Color SubColorWheel::GetColor(){
  m_detectedColor = m_colorSensor.GetColor();  
  return m_detectedColor;
}

void SubColorWheel::ConfigureTargetColors(frc::Color blue, frc::Color green, frc::Color red, frc::Color yellow){
  m_BlueTarget = blue;
  m_colorMatcher.AddColorMatch(m_BlueTarget);
  m_GreenTarget = green;
  m_colorMatcher.AddColorMatch(m_GreenTarget);
  m_RedTarget = red;
  m_colorMatcher.AddColorMatch(m_RedTarget);
  m_YellowTarget = yellow;
  m_colorMatcher.AddColorMatch(m_YellowTarget);
}

int SubColorWheel::GetColorMatch(){
  int returnColor = WHEEL_NOMATCH;
  m_detectedColor = m_colorSensor.GetColor();
  m_matchedColor = m_colorMatcher.MatchClosestColor(m_detectedColor, m_matchConfidence);

  if(m_matchedColor == m_BlueTarget){
    returnColor = WHEEL_BLUE;
  } else if(m_matchedColor == m_RedTarget){
    returnColor = WHEEL_RED; 
  } else if(m_matchedColor == m_GreenTarget){
    returnColor = WHEEL_GREEN;
  } else if(m_matchedColor == m_YellowTarget){
    returnColor = WHEEL_YELLOW;
  }
  return returnColor;
}
