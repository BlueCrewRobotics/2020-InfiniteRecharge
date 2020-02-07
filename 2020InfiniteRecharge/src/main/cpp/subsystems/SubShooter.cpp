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
#include "commands/CmdShoot.h"

SubShooter::SubShooter() : frc::Subsystem("SubShooter") {}

void SubShooter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new CmdShoot());
}

void SubShooter::Configure(){
    frc::SmartDashboard::PutNumber("Shooter/topSpeed",40.0);
    frc::SmartDashboard::PutNumber("Shooter/botSpeed",40.0);
    topShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
    topShooterMotor->SetSensorPhase(false);
    bottomShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
    bottomShooterMotor->SetSensorPhase(false);
    
    topShooterMotor->Config_kF(0,SHOOTER_TOP_KF_0, 0);
    topShooterMotor->Config_kP(0,SHOOTER_TOP_KP_0, 0);
    topShooterMotor->Config_kI(0,SHOOTER_TOP_KI_0, 0);
    topShooterMotor->Config_kD(0,SHOOTER_TOP_KD_0, 0);

    bottomShooterMotor->Config_kF(0,SHOOTER_BTM_KF_0, 0);
    bottomShooterMotor->Config_kP(0,SHOOTER_BTM_KP_0, 0);
    bottomShooterMotor->Config_kI(0,SHOOTER_BTM_KI_0, 0);
    bottomShooterMotor->Config_kD(0,SHOOTER_BTM_KD_0, 0);

    topShooterMotor->SelectProfileSlot(0, 0);
    topShooterMotor->ConfigNominalOutputForward(0, 0);
    topShooterMotor->ConfigNominalOutputReverse(0, 0);
    topShooterMotor->ConfigPeakOutputForward(1, 0);
    topShooterMotor->ConfigPeakOutputReverse(-1, 0);
    
    bottomShooterMotor->SelectProfileSlot(0, 0);
    bottomShooterMotor->ConfigNominalOutputForward(0, 0);
    bottomShooterMotor->ConfigNominalOutputReverse(0, 0);
    bottomShooterMotor->ConfigPeakOutputForward(1, 0);
    bottomShooterMotor->ConfigPeakOutputReverse(-1, 0);

    // Set current limit continuous, peak, and peak duration can only be set on
    // TalonSRX
    topShooterMotor->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT, 0);
    topShooterMotor->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT, 0);
    topShooterMotor->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT, 0);

    bottomShooterMotor->ConfigContinuousCurrentLimit(CONTINUOUS_CURRENT_LIMIT, 0);
    bottomShooterMotor->ConfigPeakCurrentLimit(PEAK_CURRENT_LIMIT, 0);
    bottomShooterMotor->ConfigPeakCurrentDuration(DURATION_CURRENT_LIMIT, 0);

/*    
    topShooterMotor->Config_kF(0, frc::SmartDashboard::GetNumber("Shooter/TOP_KF_0",SHOOTER_TOP_KF_0), 0);
    topShooterMotor->Config_kP(0, frc::SmartDashboard::GetNumber("Shooter/TOP_KP_0",SHOOTER_TOP_KP_0), 0);
    topShooterMotor->Config_kI(0, frc::SmartDashboard::GetNumber("Shooter/TOP_KI_0",SHOOTER_TOP_KI_0), 0);
    topShooterMotor->Config_kD(0, frc::SmartDashboard::GetNumber("Shooter/TOP_KD_0",SHOOTER_TOP_KD_0), 0);

    bottomShooterMotor->Config_kF(0, frc::SmartDashboard::GetNumber("Shooter/BTM_KF_0",SHOOTER_BTM_KF_0), 0);
    bottomShooterMotor->Config_kP(0, frc::SmartDashboard::GetNumber("Shooter/BTM_KP_0",SHOOTER_BTM_KP_0), 0);
    bottomShooterMotor->Config_kI(0, frc::SmartDashboard::GetNumber("Shooter/BTM_KI_0",SHOOTER_BTM_KI_0), 0);
    bottomShooterMotor->Config_kD(0, frc::SmartDashboard::GetNumber("Shooter/BTM_KD_0",SHOOTER_BTM_KD_0), 0);
*/
}

void SubShooter::Shoot(double topSpeed, double bottomSpeed) {
  // This might need to be changed on the final robot
 
  //topShooterMotor->Set(ControlMode::PercentOutput, topSpeed);
  //bottomShooterMotor->Set(ControlMode::PercentOutput, bottomSpeed);
  
  topShooterMotor->Set(ControlMode::Velocity, topSpeed);
  bottomShooterMotor->Set(ControlMode::Velocity, bottomSpeed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
