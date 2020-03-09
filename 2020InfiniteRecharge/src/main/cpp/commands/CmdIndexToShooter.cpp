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

#include "commands/CmdIndexToShooter.h"
#include "subsystems/SubShooter.h"
#include "Robot.h"

CmdIndexToShooter::CmdIndexToShooter() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subMagazine);
}

// Called just before this Command runs the first time
void CmdIndexToShooter::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdIndexToShooter::Execute() {


    Robot::m_subMagazine.MoveToPosition(-6000);
    if (Robot::m_subMagazine.GetBallCount() > 0) {
      Robot::m_subMagazine.DecreaseBallCount(1);
    }
    


    //double d_topShooter = frc::SmartDashboard::GetNumber("Shooter/topSpeed",40.0);
    //double d_botShooter = frc::SmartDashboard::GetNumber("Shooter/botSpeed",40.0);
    //double d_topShooter = 40;
    //double d_botShooter = 40;
    //Robot::m_subShooter.Shoot( d_topShooter, d_botShooter );
}

// Make this return true when this Command no longer needs to run execute()
bool CmdIndexToShooter::IsFinished() { 
    return true;
    
     }

// Called once after isFinished returns true
void CmdIndexToShooter::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdIndexToShooter::Interrupted() {}
