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
//#include "commands/CmdIndexToShooter.h"

SubShooter::SubShooter() : frc::Subsystem("SubShooter") {}

void SubShooter::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new CmdIndexToShooter());
}

void SubShooter::Configure(){
    frc::SmartDashboard::PutNumber("Shooter/topSpeed",45000.0);
    frc::SmartDashboard::PutNumber("Shooter/botSpeed",45000.0);

    topShooterMotor->SetInverted(true);
    topShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
    topShooterMotor->SetSensorPhase(false);
    topShooterMotor->ConfigClosedloopRamp(0.25, 0);


    bottomShooterMotor->SetInverted(true);
    bottomShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder,0,0);
    bottomShooterMotor->SetSensorPhase(false);
    bottomShooterMotor->ConfigClosedloopRamp(0.25, 0);

    
    
    topShooterMotor->Config_kF(0,0.021/*SHOOTER_TOP_KF_0*/, 0); //0.01704
    topShooterMotor->Config_kP(0,0.0225/*SHOOTER_TOP_KP_0*/, 0); //0.023
    topShooterMotor->Config_kI(0,SHOOTER_TOP_KI_0, 0);
    topShooterMotor->Config_kD(0,SHOOTER_TOP_KD_0, 0); 

    bottomShooterMotor->Config_kF(0,0.02/*SHOOTER_BTM_KF_0*/, 0);
    bottomShooterMotor->Config_kP(0,0.022/*SHOOTER_BTM_KP_0*/, 0);
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

    // ***********************
    // Setup Turret Motor

    turretMotor->Config_kF(0,0.0 /*TURRET_KF_0*/, 0);
    turretMotor->Config_kP(0,25.0 /*TURRET_KP_0*/, 0);
    turretMotor->Config_kI(0,0.0 /*TURRET_KI_0*/, 0);
    turretMotor->Config_kD(0,0.0 /*TURRET_KD_0*/, 0);

    turretMotor->ConfigMotionAcceleration(15 /*TURRET_ACCELERATION*/,0);
    turretMotor->ConfigMotionCruiseVelocity(15 /*TURRET_CRUISE_VELOCITY*/,0);

    // Set the talon soft limits and enable limits
    turretMotor->ConfigForwardSoftLimitThreshold(150 /*TURRET_LEFT_SOFT_LIMIT*/, 0);
    turretMotor->ConfigReverseSoftLimitThreshold(-2150 /*TURRET_RIGHT_SOFT_LIMIT*/, 0);
    turretMotor->ConfigForwardSoftLimitEnable(true /*TURRET_SOFT_LIMITS_ENABLE*/, 0);
    turretMotor->ConfigReverseSoftLimitEnable(true /*TURRET_SOFT_LIMITS_ENABLE*/, 0);

    // Configure the hard limit switches of the talon
    //turretMotor->ConfigReverseLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, 0);
    //turretMotor->ConfigForwardLimitSwitchSource(LimitSwitchSource_FeedbackConnector, LimitSwitchNormal_NormallyOpen, 0);

    turretMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::QuadEncoder, 0, 0);
  
    
    turretMotor->SetSensorPhase(false);
    turretMotor->SetInverted(false);

    turretMotor->ConfigPeakCurrentDuration(20, 0);
    turretMotor->ConfigPeakCurrentLimit(5, 0);
    turretMotor->ConfigContinuousCurrentLimit(5, 0);
    turretMotor->EnableCurrentLimit(true);

    turretMotor->SetSelectedSensorPosition(0,0,0);

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
  // This function can go away.  This is done in the magazine code
 
  //topShooterMotor->Set(ControlMode::PercentOutput, topSpeed);
  //bottomShooterMotor->Set(ControlMode::PercentOutput, bottomSpeed);
  
  //topShooterMotor->Set(ControlMode::Velocity, topSpeed);
  //bottomShooterMotor->Set(ControlMode::Velocity, bottomSpeed);
}

/*
  Spins up the wheels on the shooter in velocity closed loop.
  Parameters to pass the function are in velocity counts/100ms
*/
void SubShooter::SpinUpWheels(double topSpeed, double bottomSpeed){
  topShooterMotor->Set(ControlMode::Velocity, topSpeed);
  bottomShooterMotor->Set(ControlMode::Velocity, bottomSpeed);
}
/*
  Checks to see if the wheels on the shooter are up to speed.
  Returns true if wheels are up to speed or false if not at speed.
*/
bool SubShooter::WheelsAtSpeed(){
  int top = topShooterMotor->GetClosedLoopError();
  int bot = bottomShooterMotor->GetClosedLoopError();

  if((top < 1000 && top > -1000) && (bot < 1000 && bot > -1000)){
    return true;
  }
  return false;

}

/**
 * Set the position to servo too.
 * 
 * encoder value 
 * 
 * @param position the position to servo too
**/
void SubShooter::RotateTurret(double position){
  
  double y = position;

  // Check that turret is within operating parameters
  if(position < TURRET_MIN_ENCODER){
      y = TURRET_MIN_ENCODER;
  }
  if(position > TURRET_MAX_ENCODER){
      y = TURRET_MAX_ENCODER;
  }



        //y = TURRET_MAX_ENCODER * position + TURRET_ZERO_POSITION;

      turretMotor->Set(ControlMode::Position, y);
      std::cout << "TurretDriveTo= " << y << std::endl;
  




}

/**
 *
 * Get the current sensor position of the turret.
 * 
 **/

double SubShooter::GetTurretLocation(){
  return turretMotor->GetSelectedSensorPosition();
}



// Put methods for controlling this subsystem
// here. Call these from Commands.
