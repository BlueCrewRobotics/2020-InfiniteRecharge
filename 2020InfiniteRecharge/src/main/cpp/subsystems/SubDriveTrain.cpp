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

#include "subsystems/SubDriveTrain.h"
#include "commands/DriveWithController.h"

#include "RobotMap.h"
#include "iostream"

SubDriveTrain::SubDriveTrain() : frc::Subsystem("SubDriveTrain") {}

void SubDriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  SetDefaultCommand(new DriveWithController());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void SubDriveTrain::ConfigurePID() {
  // PID constants for Profile 0 low gear Profile 1 high gear of Talon left
  leftDriveMotor->ptr_talonSRX->Config_kF(0, frc::SmartDashboard::GetNumber("LEFT_KF_0",LEFT_KF_0), 0);
  leftDriveMotor->ptr_talonSRX->Config_kP(0, frc::SmartDashboard::GetNumber("LEFT_KP_0",LEFT_KP_0), 0);
  leftDriveMotor->ptr_talonSRX->Config_kI(0, frc::SmartDashboard::GetNumber("LEFT_KI_0",LEFT_KI_0), 0);
  leftDriveMotor->ptr_talonSRX->Config_kD(0, frc::SmartDashboard::GetNumber("LEFT_KD_0",LEFT_KD_0), 0);

  leftDriveMotor->ptr_talonSRX->Config_kF(1, frc::SmartDashboard::GetNumber("LEFT_KF_1",LEFT_KF_1), 0);
  leftDriveMotor->ptr_talonSRX->Config_kP(1, frc::SmartDashboard::GetNumber("LEFT_KP_1",LEFT_KP_1), 0);
  leftDriveMotor->ptr_talonSRX->Config_kI(1, frc::SmartDashboard::GetNumber("LEFT_KI_1",LEFT_KI_1), 0);
  leftDriveMotor->ptr_talonSRX->Config_kD(1, frc::SmartDashboard::GetNumber("LEFT_KD_1",LEFT_KD_1), 0);

  // PID constants for Profile 0 low gear Profile 1 high gear of Talon Right
  rightDriveMotor->ptr_talonSRX->Config_kF(0, frc::SmartDashboard::GetNumber("RIGHT_KF_0",RIGHT_KF_0), 0);
  rightDriveMotor->ptr_talonSRX->Config_kP(0, frc::SmartDashboard::GetNumber("RIGHT_KP_0",RIGHT_KP_0), 0);
  rightDriveMotor->ptr_talonSRX->Config_kI(0, frc::SmartDashboard::GetNumber("RIGHT_KI_0",RIGHT_KI_0), 0);
  rightDriveMotor->ptr_talonSRX->Config_kD(0, frc::SmartDashboard::GetNumber("RIGHT_KD_0",RIGHT_KD_0), 0);

  rightDriveMotor->ptr_talonSRX->Config_kF(1, frc::SmartDashboard::GetNumber("RIGHT_KF_1",RIGHT_KF_1), 0);
  rightDriveMotor->ptr_talonSRX->Config_kP(1, frc::SmartDashboard::GetNumber("RIGHT_KP_1",RIGHT_KP_1), 0);
  rightDriveMotor->ptr_talonSRX->Config_kI(1, frc::SmartDashboard::GetNumber("RIGHT_KI_1",RIGHT_KI_1), 0);
  rightDriveMotor->ptr_talonSRX->Config_kD(1, frc::SmartDashboard::GetNumber("RIGHT_KD_1",RIGHT_KD_1), 0);
}

/*
   Configure the Talons and Victors for the drive
   */
void SubDriveTrain::Configure() {

  leftDriveMotor->ptr_talonSRX->ClearStickyFaults(30);
  rightDriveMotor->ptr_talonSRX->ClearStickyFaults(30);

  // Setup followers
  // leftFollowMotor->ptr_VictorSPX->Follow(*leftDriveMotor->ptr_talonSRX);
  // leftFollowMotor->ptr_VictorSPX->SetInverted(InvertType::FollowMaster);
  // rightFollowMotor->ptr_VictorSPX->Follow(*rightDriveMotor->ptr_talonSRX);
  // rightFollowMotor->ptr_VictorSPX->SetInverted(InvertType::FollowMaster);

  // Setup followers
  leftFollowMotor->ptr_talonSRX->Follow(*leftDriveMotor->ptr_talonSRX);
  leftFollowMotor->ptr_talonSRX->SetInverted(InvertType::FollowMaster);
  rightFollowMotor->ptr_talonSRX->Follow(*rightDriveMotor->ptr_talonSRX);
  rightFollowMotor->ptr_talonSRX->SetInverted(InvertType::FollowMaster);

  // Setup encoder
  leftDriveMotor->ptr_talonSRX->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
  leftDriveMotor->ptr_talonSRX->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 1);
  leftDriveMotor->ptr_talonSRX->SetSensorPhase(false);
  rightDriveMotor->ptr_talonSRX->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
  rightDriveMotor->ptr_talonSRX->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 1);
  rightDriveMotor->ptr_talonSRX->SetSensorPhase(false);

  // Set current limit continuous, peak, and peak duration can only be set on
  // TalonSRX
  leftDriveMotor->ptr_talonSRX->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT, 0.5);
  leftDriveMotor->ptr_talonSRX->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT, 0);
  leftDriveMotor->ptr_talonSRX->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT, 0);

  rightDriveMotor->ptr_talonSRX->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT, 0.5);
  rightDriveMotor->ptr_talonSRX->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT, 0);
  rightDriveMotor->ptr_talonSRX->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT, 0);

  // Need to setup velocity PID controls
  leftDriveMotor->ptr_talonSRX->SelectProfileSlot(0, 0);
  leftDriveMotor->ptr_talonSRX->ConfigNominalOutputForward(0, 0);
  leftDriveMotor->ptr_talonSRX->ConfigNominalOutputReverse(0, 0);
  leftDriveMotor->ptr_talonSRX->ConfigPeakOutputForward(1, 0);
  leftDriveMotor->ptr_talonSRX->ConfigPeakOutputReverse(-1, 0);

  rightDriveMotor->ptr_talonSRX->SelectProfileSlot(0, 0);
  rightDriveMotor->ptr_talonSRX->ConfigNominalOutputForward(0, 0);
  rightDriveMotor->ptr_talonSRX->ConfigNominalOutputReverse(0, 0);
  rightDriveMotor->ptr_talonSRX->ConfigPeakOutputForward(1, 0);
  rightDriveMotor->ptr_talonSRX->ConfigPeakOutputReverse(-1, 0);

  // PID constants for Profile 0 low gear Profile 1 high gear of Talon left
  frc::SmartDashboard::PutNumber("LEFT_KF_0",LEFT_KF_0);
  frc::SmartDashboard::PutNumber("LEFT_KP_0",LEFT_KP_0);
  frc::SmartDashboard::PutNumber("LEFT_KI_0",LEFT_KI_0);
  frc::SmartDashboard::PutNumber("LEFT_KD_0",LEFT_KD_0);

  leftDriveMotor->ptr_talonSRX->Config_kF(0, LEFT_KF_0, 0);
  leftDriveMotor->ptr_talonSRX->Config_kP(0, LEFT_KP_0, 0);
  leftDriveMotor->ptr_talonSRX->Config_kI(0, LEFT_KI_0, 0);
  leftDriveMotor->ptr_talonSRX->Config_kD(0, LEFT_KD_0, 0);

  frc::SmartDashboard::PutNumber("LEFT_KF_1",LEFT_KF_1);
  frc::SmartDashboard::PutNumber("LEFT_KP_1",LEFT_KP_1);
  frc::SmartDashboard::PutNumber("LEFT_KI_1",LEFT_KI_1);
  frc::SmartDashboard::PutNumber("LEFT_KD_1",LEFT_KD_1);

  leftDriveMotor->ptr_talonSRX->Config_kF(1, LEFT_KF_1, 0);
  leftDriveMotor->ptr_talonSRX->Config_kP(1, LEFT_KP_1, 0);
  leftDriveMotor->ptr_talonSRX->Config_kI(1, LEFT_KI_1, 0);
  leftDriveMotor->ptr_talonSRX->Config_kD(1, LEFT_KD_1, 0);

  // PID constants for Profile 0 low gear Profile 1 high gear of Talon Right

  frc::SmartDashboard::PutNumber("RIGHT_KF_0",RIGHT_KF_0);
  frc::SmartDashboard::PutNumber("RIGHT_KP_0",RIGHT_KP_0);
  frc::SmartDashboard::PutNumber("RIGHT_KI_0",RIGHT_KI_0);
  frc::SmartDashboard::PutNumber("RIGHT_KD_0",RIGHT_KD_0);

  rightDriveMotor->ptr_talonSRX->Config_kF(0, RIGHT_KF_0, 0);
  rightDriveMotor->ptr_talonSRX->Config_kP(0, RIGHT_KP_0, 0);
  rightDriveMotor->ptr_talonSRX->Config_kI(0, RIGHT_KI_0, 0);
  rightDriveMotor->ptr_talonSRX->Config_kD(0, RIGHT_KD_0, 0);

  frc::SmartDashboard::PutNumber("RIGHT_KF_1",RIGHT_KF_1);
  frc::SmartDashboard::PutNumber("RIGHT_KP_1",RIGHT_KP_1);
  frc::SmartDashboard::PutNumber("RIGHT_KI_1",RIGHT_KI_1);
  frc::SmartDashboard::PutNumber("RIGHT_KD_1",RIGHT_KD_1);

  rightDriveMotor->ptr_talonSRX->Config_kF(1, RIGHT_KF_1, 0);
  rightDriveMotor->ptr_talonSRX->Config_kP(1, RIGHT_KP_1, 0);
  rightDriveMotor->ptr_talonSRX->Config_kI(1, RIGHT_KI_1, 0);
  rightDriveMotor->ptr_talonSRX->Config_kD(1, RIGHT_KD_1, 0);

  // Set the Talon ramp rate in seconds from neutral to full
  leftDriveMotor->ptr_talonSRX->ConfigClosedloopRamp(DRIVE_RAMP_TIME, 0);
  rightDriveMotor->ptr_talonSRX->ConfigClosedloopRamp(DRIVE_RAMP_TIME, 0);
}

// Set the ramp rate on the drive
void SubDriveTrain::SetRamp(double ramp) {
  leftDriveMotor->ptr_talonSRX->ConfigClosedloopRamp(ramp, 0);
  rightDriveMotor->ptr_talonSRX->ConfigClosedloopRamp(ramp, 0);
}
// Drive
void SubDriveTrain::Drive(double speed, double rotation) {
  // Drive

  driveTrain->SetDeadband(0.02);
  driveTrain->ArcadeDrive(speed, rotation, true);
}

void SubDriveTrain::ResetEncoders() {
  leftDriveMotor->ResetSensorPosition();
  rightDriveMotor->ResetSensorPosition();
}

void SubDriveTrain::ConfigureAuto() {
  leftDriveMotor->ConfigureMotionAcceleration(500, 10);
  rightDriveMotor->ConfigureMotionAcceleration(500, 10);
  leftDriveMotor->ConfigureMotionVelocity(500, 10);
  rightDriveMotor->ConfigureMotionVelocity(500, 10);
}

void SubDriveTrain::AutoDrive(double leftrotations, double rightrotations) {
  leftrotations = leftrotations * 4096; // Set up gear ratio here
  rightrotations = rightrotations * 4096 * -1;
  leftDriveMotor->SetMotionMagic(leftrotations);
  rightDriveMotor->SetMotionMagic(rightrotations);
}

void SubDriveTrain::ConfigMotionMagicCurve(int strength) {
  leftDriveMotor->ConfigureMotionCurveStrength(strength, 0);
  rightDriveMotor->ConfigureMotionCurveStrength(strength, 0);
}