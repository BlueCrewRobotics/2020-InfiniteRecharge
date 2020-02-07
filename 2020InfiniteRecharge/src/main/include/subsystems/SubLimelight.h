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
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

class SubLimelight : public frc::Subsystem {
 public:
  SubLimelight();
  void InitDefaultCommand() override;
  
  // Get whether or not limelight has a target
  bool GetTarget();

  



 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  
  //nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("<variablename>",0.0);

  std::shared_ptr<NetworkTable> tblLimelight = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
};
