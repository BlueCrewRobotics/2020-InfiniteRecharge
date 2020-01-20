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

#include "subsystems/SubShooter.h"

#include "RobotMap.h"

SubShooter::SubShooter() : frc::Subsystem("SubShooter") {}

void SubShooter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void SubShooter::Configure(){
    frc::SmartDashboard::PutNumber("Shooter/topSpeed",0.0);
    frc::SmartDashboard::PutNumber("Shooter/botSpeed",0.0);
    topShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
    bottomShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
    
}

void SubShooter::Shoot(double topSpeed, double bottomSpeed) {
  // This might need to be changed on the final robot
 
  topShooterMotor->Set(ControlMode::PercentOutput, topSpeed);
  bottomShooterMotor->Set(ControlMode::PercentOutput, bottomSpeed);
  
  //topShooterMotor->Set(ControlMode::Velocity, topSpeed);
  //bottomShooterMotor->Set(ControlMode::Velocity, bottomSpeed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
