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
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

class SubLimelight : public frc::Subsystem {
 public:
  SubLimelight();
  void InitDefaultCommand() override;
  
  // Get whether or not limelight has a target
  bool GetTarget();

  // Get horizontal Offset from Crosshair to target
  double GetHorizontalOffset();

  // Get the distance from the target
  double GetDistanceToTarget();

  // Get the skew of the target
  double GetSkew();

  // Get the camera mounting angle
  double GetCameraMountAngle(double distance);

  // Set the Limelight LED state
  void SetLEDState(int mode);

  // Set the Camera mode
  void SetCameraMode(int mode);

  // Select the pipline to use
  void SelectPipeline(int pipeline);
  
  // Select the limelight streaming mode
  void SelectStreamMode(int mode);
  
  // Select the limelight snapshot mode
  void SelectSnapshotMode(int mode);

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  
  //nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("<variablename>",0.0);

  std::shared_ptr<NetworkTable> tblLimelight = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
};
