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

#include "RobotMap.h"
#include <frc/commands/Subsystem.h>
#include "common/BC_Switch.h"
#include <ctre/Phoenix.h>

//#include "rev/Rev2mDistanceSensor.h"

class SubMagazine : public frc::Subsystem {
 public:
  SubMagazine();
  void InitDefaultCommand() override;
  void MoveToPosition(int blocks);
  void UpdateSensors();
  int GetCurrentPosition();
  void Configure();
  //int GetBallCount();
  //int GetMotorVelocity();
  void ResetEncoderPosition();
  void Test();

  bool intakeShootMode = 0;
  bool sensors[5] = {false, false, false, false, false};
  

  int currentPosition = 0;
  int ballCount = 0;
  
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  
  int encoderPosition = 0;
  
  bool intakeBreakSensorLock = false;


  // Sets up break sensors
  frc::DigitalInput* m_ballDetector = new frc::DigitalInput(0);
  

  //BC_Switch* m_ballDetector = new BC_Switch(BALL_DETECTOR);
  BC_Switch* m_ballPosition1 = new BC_Switch(BALL_POS_1);
  BC_Switch* m_ballPosition2 = new BC_Switch(BALL_POS_2);
  BC_Switch* m_ballPosition3 = new BC_Switch(BALL_POS_3);
  BC_Switch* m_ballPosition4 = new BC_Switch(BALL_POS_4); 

  TalonSRX *magazineMotor = new TalonSRX(MAGAZINE_MOTOR);

  //rev::Rev2mDistanceSensor *distSensor = new rev::Rev2mDistanceSensor(rev::Rev2mDistanceSensor::Port::kMXP,rev::Rev2mDistanceSensor::DistanceUnit::kInches,rev::Rev2mDistanceSensor::RangeProfile::kHighSpeed);
};
