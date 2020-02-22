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
#include "rev/CANSparkMax.h"

class SubLifter : public frc::Subsystem {
 public:
  SubLifter();
  void InitDefaultCommand() override;
  void ConfigureMotors();
  void EngageLifter();
  void LifterUp();
  void LifterDown();
  void DisengageLifter();

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  rev::CANSparkMax lifterEngageMotor{0, rev::CANSparkMax::MotorType::kBrushless}; // Change the zero to an address in robotmap
  rev::CANPIDController pidController = lifterEngageMotor.GetPIDController();
  rev::CANEncoder lifterEngageEncoder = lifterEngageMotor.GetEncoder();

};
