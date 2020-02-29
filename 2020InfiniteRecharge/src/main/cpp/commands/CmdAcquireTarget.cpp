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

#include "commands/CmdAcquireTarget.h"
#include "subsystems/SubShooter.h"
#include "Robot.h"

CmdAcquireTarget::CmdAcquireTarget() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subShooter);
}

// Called just before this Command runs the first time
void CmdAcquireTarget::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdAcquireTarget::Execute() {

    double targetPosition;
    double turretPostion;
		double d_gain = 0.65;

    // Check to see if limelight has a target
    if(Robot::m_subLimelight.GetTarget()==true){

      
		  double d_targetAngle = Robot::m_subLimelight.GetHorizontalOffset(); 

		  //rotation = (d_gain*(((30-d_targetCenter)/30) - (d_targetAngle/30)));
		  targetPosition = (-1*(d_targetAngle/29.8))*d_gain;
    }

/*
      position = TURRET_MAX_ENCODER * position + TURRET_ZERO_POSITION;
      Robot::m_subShooter.RotateTurret(position);
    
    
      Robot::m_subMagazine.intakeShootMode = 1;
    }
    // If limelight doesn't have a target send turret to default locations
    // If this is the case the driver must turn the robot toward the target to acquire the target
    else
    {
      position = 0;
      Robot::m_subShooter.RotateTurret(position);
    }
    
 */   
}

// Make this return true when this Command no longer needs to run execute()
bool CmdAcquireTarget::IsFinished() { 
    return false;
    
     }

// Called once after isFinished returns true
void CmdAcquireTarget::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdAcquireTarget::Interrupted() {}
