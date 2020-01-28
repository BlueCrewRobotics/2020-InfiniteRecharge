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

#pragma once

#include <frc/commands/Subsystem.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include "RobotMap.h"
#include <frc/smartdashboard/SmartDashboard.h>


class SubColorWheel : public frc::Subsystem {
 public:
  SubColorWheel();
  void InitDefaultCommand() override;
  void ReadColor();
  frc::Color GetColor();
  frc::Color WheelColors[4] = {frc::Color(0.1266, 0.4252, 0.4484), frc::Color(0.1661, 0.5790, 0.2550), frc::Color(0.5172, 0.3492, 0.1334), frc::Color(0.3131, 0.5597, 0.1271)};
  void ConfigureTargetColors(frc::Color blue, frc::Color green, frc::Color red, frc::Color yellow);
  int GetColorMatch();
  
  std::string gameData;


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
  double m_matchConfidence = 0.0005;
  
  // Target Colors
  frc::Color m_BlueTarget = frc::Color(0.1266, 0.4252, 0.4484);
  frc::Color m_GreenTarget = frc::Color(0.1661, 0.5790, 0.2550);
  frc::Color m_RedTarget = frc::Color(0.5172, 0.3492, 0.1334);
  frc::Color m_YellowTarget = frc::Color(0.3131, 0.5597, 0.1271);


};
