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

#include "subsystems/SubMagazine.h"

#include "RobotMap.h"

SubMagazine::SubMagazine() : frc::Subsystem("SubMagazine") {}

void SubMagazine::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  SetDefaultCommand(new CmdMagazine());
}

void SubMagazine::Configure() {
  // Configure the setting for the PID etc.
  magazineMotor->Config_kF(0, 0, 0);
  magazineMotor->Config_kP(0, 0, 0);
  magazineMotor->Config_kI(0, 0, 0);
  magazineMotor->Config_kD(0, 0, 0);

  // Configure the cruise velocity and the acceleration
  magazineMotor->ConfigMotionCruiseVelocity(1000, 0);
  magazineMotor->ConfigMotionAcceleration(1000, 0);

  magazineMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
  magazineMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 1);
  magazineMotor->SetSensorPhase(true);
  // magazineMotor->SetInverted(InvertType::InvertMotorOutput);

  magazineMotor->ConfigPeakCurrentDuration(1, 0);
  magazineMotor->ConfigPeakCurrentLimit(15, 0);
  magazineMotor->ConfigContinuousCurrentLimit(15, 0);
  magazineMotor->EnableCurrentLimit(true);

  magazineMotor->ConfigOpenloopRamp(0.25, 0);
  magazineMotor->ConfigClosedloopRamp(0.25, 0);

}

// Moves the magazine to a specified servo position(blocks are equal to approx. 7 inches)
void SubMagazine::MoveToPosition(int blocks) {
  encoderPosition = blocks * 100; // CHANGE 100 TO VALUE OF ENCODER MOVING 7 - 8 INCHES
  magazineMotor->Set(ControlMode::Position, encoderPosition);
  currentPosition = blocks;
}

int SubMagazine::GetCurrentPosition() {

}





void SubMagazine::UpdateSensors() {
  sensors[0] = m_ballDetector->GetSwitchState();
  sensors[1] = m_ballPosition1->GetSwitchState();
  sensors[2] = m_ballPosition2->GetSwitchState();
  sensors[3] = m_ballPosition3->GetSwitchState();
  sensors[4] = m_ballPosition4->GetSwitchState();
}

int SubMagazine::GetBallCount() {
  ballCount = ballCount + sensors[1];
  ballCount = ballCount + sensors[2];
  ballCount = ballCount + sensors[3];
  ballCount = ballCount + sensors[4];
  return ballCount;
}

int SubMagazine::GetMotorVelocity() {
  return magazineMotor->GetSelectedSensorVelocity();
}

void SubMagazine::ResetEncoderPosition() {
  magazineMotor->SetSelectedSensorPosition(0,0,0);
  currentPosition = 0;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
