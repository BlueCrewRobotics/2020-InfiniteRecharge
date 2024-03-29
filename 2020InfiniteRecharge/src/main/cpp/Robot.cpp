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

#include "Robot.h"

#include <frc/commands/Scheduler.h>
#include <frc/smartdashboard/SmartDashboard.h>

ExampleSubsystem Robot::m_subsystem;
OI Robot::m_oi;

SubDriveTrain Robot::m_subDriveTrain;
SubPCM Robot::m_subPCM;
SubShooter Robot::m_subShooter;
SubColorWheel Robot::m_subColorWheel;
SubIntake Robot::m_subIntake;
SubNavX Robot::m_subNavX;
SubLimelight Robot::m_subLimelight;
SubMagazine Robot::m_subMagazine;
SubLifter Robot::m_subLifter;
Timer Robot::m_Timer;

void Robot::RobotInit() {
  m_chooser.SetDefaultOption("Default Auto", &m_defaultAuto);
  m_chooser.AddOption("My Auto", &m_myAuto);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  
  m_subDriveTrain.Configure();
  m_subPCM.Configure();
  m_subShooter.Configure();
  m_subDriveTrain.ConfigurePID();
  m_subDriveTrain.ConfigMotionMagicCurve(4);
  m_subDriveTrain.ConfigureAuto();
  m_subMagazine.Configure();
  m_subLifter.ConfigureMotors();
  m_subLimelight.SelectStreamMode(1);
  m_subLimelight.SetLEDState(1);

}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {
  m_subMagazine.SetBallCount(3);
}

void Robot::DisabledPeriodic() { frc::Scheduler::GetInstance()->Run(); }

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit() {
  // std::string autoSelected = frc::SmartDashboard::GetString(
  //     "Auto Selector", "Default");
  // if (autoSelected == "My Auto") {
  //   m_autonomousCommand = &m_myAuto;
  // } else {
  //   m_autonomousCommand = &m_defaultAuto;
  // }
  
  m_Timer.Reset();
  m_Timer.Start();
  m_subMagazine.SetBallCount(3);

  //m_autonomousCommand = m_chooser.GetSelected();
  //m_subLimelight.SetLEDState(1);
  m_subDriveTrain.ResetEncoders();
  
  /*m_autonomousCommand = new AutoCmdGrp();
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Start();
  }*/
}

void Robot::AutonomousPeriodic() { 
  frc::Scheduler::GetInstance()->Run();
  //m_oi.PollController(); // DO I NEED THIS HERE?
  //m_oi.PollMagazine(); // DO I NEED THIS HERE?
  //m_oi.PollController();
  m_oi.PollAutonomous();

   }

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomousCommand != nullptr) {
    m_autonomousCommand->Cancel();
    m_autonomousCommand = nullptr;
  }
  m_subLimelight.SetLEDState(1);
  Robot::m_subMagazine.ResetEncoderPosition();;
  Robot::m_subMagazine.MoveToPosition(0); 
  
}

void Robot::TeleopPeriodic() { 
  frc::Scheduler::GetInstance()->Run();
  //m_oi.PollController();
  m_subColorWheel.gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
    frc::SmartDashboard::PutNumber("ballCount",Robot::m_subMagazine.GetBallCount());
  //m_subMagazine.Test();
  //m_subLimelight.SetLEDState(1);
 
  //m_subMagazine.UpdateSensors();
  m_oi.PollController();
  m_oi.PollMagazine();
   }

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
