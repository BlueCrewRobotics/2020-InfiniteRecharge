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
#include "frc/Compressor.h"
#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class SubPCM : public frc::Subsystem {
public:
  SubPCM();
  void InitDefaultCommand() override;
  void Configure();
  frc::Solenoid *ptr_GearSolenoid =
      new frc::Solenoid(PCM_BOTTOM, BTM_GEARSHIFT);
  // frc::Solenoid* ptr_ClampSolenoid = new frc::Solenoid(PCM_TOP,
  // TOP_CLAMP_SOLENOID); frc::Solenoid* ptr_TiltSolenoid = new
  // frc::Solenoid(PCM_TOP, TOP_CARGO_TILT); frc::Solenoid* ptr_HatchSolenoid =
  // new frc::Solenoid(PCM_TOP, TOP_HATCH_GRABBER);

private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  frc::Compressor *compressor = new frc::Compressor(0);
  // frc::Solenoid exampleSolenoid {1};
};
