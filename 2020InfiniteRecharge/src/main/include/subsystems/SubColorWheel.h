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

#pragma once

#include <frc/commands/Subsystem.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "RobotMap.h"

class SubColorWheel : public frc::Subsystem {
 public:
  SubColorWheel();
  void InitDefaultCommand() override;
  frc::Color GetColor();
  void ConfigureTargetColors(frc::Color blue, frc::Color green, frc::Color red, frc::Color yellow);
  int GetColorMatch();
  
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  
  // Configures the color sensor to communicate on the I2C port of the RoboRio
  rev::ColorSensorV3 m_colorSensor{frc::I2C::Port::kOnboard};
  
  // Used for matching color that have been read from the color sensor
  rev::ColorMatch m_colorMatcher;
  
  // Returned value from the matched color
  frc::Color m_matchedColor;

  // Detected color as read from the color sensor
  frc::Color m_detectedColor;

  // Confidence of matched value
  double m_matchConfidence = 0.95;
  
  // Target Colors
  frc::Color m_BlueTarget = frc::Color(0.143, 0.427, 0.429);
  frc::Color m_GreenTarget = frc::Color(0.197, 0.561, 0.240);
  frc::Color m_RedTarget = frc::Color(0.561, 0.232, 0.114);
  frc::Color m_YellowTarget = frc::Color(0.361, 0.524, 0.113);


};
