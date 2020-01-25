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
#include <frc/WPILib.h>
#include "BC_VictorSPX.h"

class SubIntake : public frc::Subsystem {
 public:
  SubIntake();
  void InitDefaultCommand() override;
  void ExtendIntake(bool Extention);
  void RunIntake(double Speed);

 private:
  VictorSPX *intakeMotor = new VictorSPX(7);
  frc::Solenoid *extendSolenoid = new frc::Solenoid(9, 1);
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
};
