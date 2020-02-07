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
//#include <frc/WPILib.h>
#include "BC_TalonSRX.h"
#include <frc/smartdashboard/SmartDashboard.h>

class SubShooter : public frc::Subsystem {
 public:
  SubShooter();
  void InitDefaultCommand() override;
  void Configure();
  void Shoot(double topSpeed, double bottomSpeed);

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  TalonSRX *topShooterMotor = new TalonSRX(SHOOTER_TOP_ADDR);
  TalonSRX *bottomShooterMotor = new TalonSRX(SHOOTER_BTM_ADDR);
  TalonSRX *turret = new TalonSRX(SHOOTER_TURRET_ADDR);

};
