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

//#include "frc/WPILib.h"
#include <ctre/Phoenix.h>
#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DriverStation.h>

#include "OI.h"
#include "commands/ExampleCommand.h"
#include "commands/MyAutoCommand.h"
#include "subsystems/ExampleSubsystem.h"
#include "commands/CmdSwitchGear.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubPCM.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "subsystems/SubShooter.h"
#include "commands/CmdSpinShooterWheels.h"
#include "commands/CmdShoot.h"
#include "subsystems/SubColorWheel.h"
#include "subsystems/SubIntake.h"
#include "subsystems/SubNavX.h"
#include "commands/CmdColorSpin.h"
#include "subsystems/SubLimelight.h"
#include "autocommands/AutoCmdDrive.h"
#include "subsystems/SubMagazine.h"
#include "commands/CmdMagazine.h"
#include "commands/CmdNumberSpin.h"
#include "commands/CmdIntakeExtend.h"
#include "commands/CmdIntakeRetract.h"

class Robot : public frc::TimedRobot {
 public:
  static ExampleSubsystem m_subsystem;
  static OI m_oi;
  static SubDriveTrain m_subDriveTrain;
	static SubPCM m_subPCM;
  static SubShooter m_subShooter;
  static SubColorWheel m_subColorWheel;
  static SubIntake m_subIntake;
  static SubNavX m_subNavX;
  static SubLimelight m_subLimelight;
  static SubMagazine m_subMagazine;
  
  
  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.
  frc::Command* m_autonomousCommand = nullptr;
  ExampleCommand m_defaultAuto;
  MyAutoCommand m_myAuto;
  frc::SendableChooser<frc::Command*> m_chooser;
};
