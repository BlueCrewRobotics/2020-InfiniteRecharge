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

#include <iostream>
using namespace std;

SubMagazine::SubMagazine() : frc::Subsystem("SubMagazine") {}

void SubMagazine::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  //SetDefaultCommand(new CmdMagazine());
}
// Configures Magazine Motor
void SubMagazine::Configure() {
  // Configure the setting for the PID etc.
  magazineMotor->Config_kF(0, 0, 0);
  magazineMotor->Config_kP(0, 0.26, 0);
  magazineMotor->Config_kI(0, 0, 0);
  magazineMotor->Config_kD(0, 0, 0);

  // Configure the cruise velocity and the acceleration
  magazineMotor->ConfigMotionCruiseVelocity(5000, 0);
  magazineMotor->ConfigMotionAcceleration(15000, 0);

  magazineMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
  magazineMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 1);
  magazineMotor->SetSensorPhase(true);
  // magazineMotor->SetInverted(InvertType::InvertMotorOutput);

  magazineMotor->ConfigPeakCurrentDuration(1, 0);
  magazineMotor->ConfigPeakCurrentLimit(15, 0);
  magazineMotor->ConfigContinuousCurrentLimit(15, 0);
  magazineMotor->EnableCurrentLimit(true);

  //magazineMotor->ConfigOpenloopRamp(0.25, 0);
  //magazineMotor->ConfigClosedloopRamp(0.25, 0);

}

// Moves the magazine to a specified servo position(blocks are equal to approx. 7 inches)
void SubMagazine::AddToPosition(int position) {
  //encoderPosition = blocks * -6000; 
  //encoderPosition = encoderPosition + -4362;
  double currentPos = magazineMotor->GetSelectedSensorPosition(0);
  magazineMotor->Set(ControlMode::Position, (currentPos + position));
  
}

void SubMagazine::MoveToPosition(int position) {
  magazineMotor->Set(ControlMode::Position, (position));

}

// Used for testing 
void SubMagazine::Test() {
  //sensors[0] = m_ballDetector->Get();
  std::cout << currentPosition << std::endl;
}

// Updates break sensor
//void SubMagazine::UpdateSensors() {
//  sensors[0] = m_ballDetector->Get();
//  sensors[0] = !sensors[0];}
  

// Get break sensor
bool SubMagazine::GetSensor() {
  return m_ballDetector->Get();
  
  
}

bool SubMagazine::GetSensorBackup() {
  return m_ballDetectorBackup->Get();

}

// Resets encoder position of the magazine
void SubMagazine::ResetEncoderPosition() {
  magazineMotor->SetSelectedSensorPosition(0,0,0);
  currentPosition = 0;
  MoveToPosition(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

int SubMagazine::GetMotorError() {
  return magazineMotor->GetClosedLoopError();
}

int SubMagazine::GetBallCount() {
  return ballCount;
}

void SubMagazine::IncreaseBallCount(int amount) {
  ballCount = ballCount + amount;
}

void SubMagazine::DecreaseBallCount(int amount) {
  ballCount = ballCount - amount;
}

void SubMagazine::Jog(double amount){
  double position = magazineMotor->GetSelectedSensorPosition(0);
  magazineMotor->Set(ControlMode::Position,(position + amount));
}

void SubMagazine::SetBallCount(int value){
  ballCount = value;
}
