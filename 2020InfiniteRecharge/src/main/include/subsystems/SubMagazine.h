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
#include "common/BC_Switch.h"
//#include "rev/Rev2mDistanceSensor.h"

class SubMagazine : public frc::Subsystem {
 public:
  SubMagazine();
  void InitDefaultCommand() override;
  void MoveForward(int blocks);
  void MoveBackward(int blocks);
  bool GetBreakSwitch();
  int GetBallCount();

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  int ballCount = 0;
  bool currentSwitchState = 0;
  BC_Switch* m_intakeSwitch = new BC_Switch(0);

  //rev::Rev2mDistanceSensor *distSensor = new rev::Rev2mDistanceSensor(rev::Rev2mDistanceSensor::Port::kMXP,rev::Rev2mDistanceSensor::DistanceUnit::kInches,rev::Rev2mDistanceSensor::RangeProfile::kHighSpeed);
};
