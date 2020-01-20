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

#include "subsystems/SubColorWheel.h"
#include "commands/CmdReadColor.h"

#include "RobotMap.h"


SubColorWheel::SubColorWheel() : frc::Subsystem("SubColorWheel") {}

void SubColorWheel::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new CmdReadColor());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void SubColorWheel::ReadColor(){
  m_detectedColor = m_colorSensor.GetColor();  
  
  frc::SmartDashboard::PutNumber("SubColorWheel/Red", m_detectedColor.red);
  frc::SmartDashboard::PutNumber("SubColorWheel/Green", m_detectedColor.green);
  frc::SmartDashboard::PutNumber("SubColorWheel/Blue", m_detectedColor.blue);
  frc::SmartDashboard::PutNumber("SubColorWheel/ColorMatch", this->GetColorMatch());

}

frc::Color SubColorWheel::GetColor(){
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
  m_matchConfidence = 0.60;
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
  frc::SmartDashboard::PutNumber("SubColorWheel/ColorMatch.red",m_matchedColor.red);
  frc::SmartDashboard::PutNumber("SubColorWheel/ColorMatch.green",m_matchedColor.green);
  frc::SmartDashboard::PutNumber("SubColorWheel/ColorMatch.blue",m_matchedColor.blue);
  frc::SmartDashboard::PutNumber("SubColorWheel/Confidence",m_matchConfidence);
  frc::SmartDashboard::PutNumber("SubColorWheel/ColorSelected",returnColor);

  return returnColor;
}

