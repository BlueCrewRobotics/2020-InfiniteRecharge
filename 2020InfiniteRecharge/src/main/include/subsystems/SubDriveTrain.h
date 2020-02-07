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

#include "BC_TalonSRX.h"
#include "BC_VictorSPX.h"
#include "RobotMap.h"
#include "frc/SpeedController.h"
#include <ctre/Phoenix.h>
//#include <frc/WPILib.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/commands/Subsystem.h>

class SubDriveTrain : public frc::Subsystem {

public:
  SubDriveTrain();
  void InitDefaultCommand() override;
  void Configure();
  void ConfigurePID();
  void Drive(double speed, double rotation);
  void DriveVelocityControl(double speed, double rotation);
  void SetRamp(double ramp);
  void ResetEncoders();
  void ConfigureAuto();
  void AutoDrive(double leftrotations, double rightrotations);
  void ConfigMotionMagicCurve(int strength);
  // void Set(double speed) ;

  // private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  /*
     WPI_TalonSRX* leftDriveMotor = new WPI_TalonSRX(MOTOR_LEFT_MASTER);
     WPI_TalonSRX* rightDriveMotor = new WPI_TalonSRX(MOTOR_RIGHT_MASTER);
     WPI_VictorSPX* leftFollowMotor = new WPI_VictorSPX(MOTOR_LEFT_FOLLOWER);
     WPI_VictorSPX* rightFollowMotor = new WPI_VictorSPX(MOTOR_RIGHT_FOLLOWER);
     */

  BC_TalonSRX *leftDriveMotor = new BC_TalonSRX(MOTOR_LEFT_MASTER);
  BC_TalonSRX *rightDriveMotor = new BC_TalonSRX(MOTOR_RIGHT_MASTER);

  BC_TalonSRX *leftFollowMotor = new BC_TalonSRX(MOTOR_LEFT_FOLLOWER);
  BC_TalonSRX *rightFollowMotor = new BC_TalonSRX(MOTOR_RIGHT_FOLLOWER);

  //		BC_VictorSPX* leftFollowMotor = new
  //BC_VictorSPX(MOTOR_LEFT_FOLLOWER); 		BC_VictorSPX* rightFollowMotor = new
  //BC_VictorSPX(MOTOR_RIGHT_FOLLOWER);

  /*
     BC_TalonSRX* leftDriveMotor = new BC_TalonSRX(MOTOR_LEFT_MASTER);
     BC_TalonSRX* rightDriveMotor = new BC_TalonSRX(MOTOR_RIGHT_MASTER);
     BC_VictorSPX* leftFollowMotor = new BC_VictorSPX(MOTOR_LEFT_FOLLOWER);
     BC_VictorSPX* rightFollowMotor = new BC_VictorSPX(MOTOR_RIGHT_FOLLOWER);
     */

  frc::DifferentialDrive *driveTrain = new frc::DifferentialDrive(*leftDriveMotor, *rightDriveMotor);
};
