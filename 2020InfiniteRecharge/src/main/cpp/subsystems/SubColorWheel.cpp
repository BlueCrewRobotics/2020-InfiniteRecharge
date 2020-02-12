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
#include <iostream>
using namespace std;

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
  double MatchedColor = 0;
  m_matchConfidence = 0.05;
  m_detectedColor = m_colorSensor.GetColor();
  
  if (m_detectedColor.red >= WheelColors[WHEEL_BLUE].red - m_matchConfidence && m_detectedColor.red <= WheelColors[WHEEL_BLUE].red + m_matchConfidence) {
    if (m_detectedColor.green >= WheelColors[WHEEL_BLUE].green - m_matchConfidence && m_detectedColor.green <= WheelColors[WHEEL_BLUE].green + m_matchConfidence) {
      if (m_detectedColor.red >= WheelColors[WHEEL_BLUE].red - m_matchConfidence && m_detectedColor.red <= WheelColors[WHEEL_BLUE].red + m_matchConfidence) {
          returnColor = WHEEL_BLUE;
  } } }

  if (m_detectedColor.blue >= WheelColors[WHEEL_GREEN].blue - m_matchConfidence && m_detectedColor.red <= WheelColors[WHEEL_GREEN].red + m_matchConfidence) {
    if (m_detectedColor.green >= WheelColors[WHEEL_GREEN].green - m_matchConfidence && m_detectedColor.green <= WheelColors[WHEEL_GREEN].green + m_matchConfidence) {
      if (m_detectedColor.red >= WheelColors[WHEEL_GREEN].red - m_matchConfidence && m_detectedColor.red <= WheelColors[WHEEL_GREEN].red + m_matchConfidence) {
          returnColor = WHEEL_GREEN;
  } } } 

  if (m_detectedColor.red >= WheelColors[WHEEL_RED].red - m_matchConfidence && m_detectedColor.red <= WheelColors[WHEEL_RED].red + m_matchConfidence) {
    if (m_detectedColor.green >= WheelColors[WHEEL_RED].green - m_matchConfidence && m_detectedColor.green <= WheelColors[WHEEL_RED].green + m_matchConfidence) {
      if (m_detectedColor.red >= WheelColors[WHEEL_RED].red - m_matchConfidence && m_detectedColor.red <= WheelColors[WHEEL_RED].red + m_matchConfidence) {
          returnColor = WHEEL_RED;
  } } }

  if (m_detectedColor.red >= WheelColors[WHEEL_YELLOW].red - m_matchConfidence && m_detectedColor.red <= WheelColors[WHEEL_YELLOW].red + m_matchConfidence) {
    if (m_detectedColor.green >= WheelColors[WHEEL_YELLOW].green - m_matchConfidence && m_detectedColor.green <= WheelColors[WHEEL_YELLOW].green + m_matchConfidence) {
      if (m_detectedColor.red >= WheelColors[WHEEL_YELLOW].red - m_matchConfidence && m_detectedColor.red <= WheelColors[WHEEL_YELLOW].red + m_matchConfidence) {
          returnColor = WHEEL_YELLOW;
  } } }


  frc::SmartDashboard::PutNumber("SubColorWheel/ColorMatch.red",m_matchedColor.red);
  frc::SmartDashboard::PutNumber("SubColorWheel/ColorMatch.green",m_matchedColor.green);
  frc::SmartDashboard::PutNumber("SubColorWheel/ColorMatch.blue",m_matchedColor.blue);
  frc::SmartDashboard::PutNumber("SubColorWheel/Confidence",m_matchConfidence);
  frc::SmartDashboard::PutNumber("SubColorWheel/ColorSelected",returnColor);

  std::cout << returnColor << std::endl;

  return returnColor;
}

void SubColorWheel::RunColor(double speed){
    colorMotor->Set(ControlMode::PercentOutput, speed);
}