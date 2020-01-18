/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include "BC_TalonSRX.h"

class SubShooter : public frc::Subsystem {
 public:
  SubShooter();
  void InitDefaultCommand() override;
  void Shoot(double topSpeed, double bottomSpeed);

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

  TalonSRX *topShooterMotor = new TalonSRX(5);
  TalonSRX *bottomShooterMotor = new TalonSRX(6);

};
