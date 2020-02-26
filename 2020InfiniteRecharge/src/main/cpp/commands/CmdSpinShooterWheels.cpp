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

#include "commands/CmdSpinShooterWheels.h"
#include "subsystems/SubShooter.h"
#include "Robot.h"

CmdSpinShooterWheels::CmdSpinShooterWheels() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subShooter);
}

// Called just before this Command runs the first time
void CmdSpinShooterWheels::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void CmdSpinShooterWheels::Execute() {

    //double d_topShooter = frc::SmartDashboard::GetNumber("Shooter/topSpeed",40.0);
    //double d_botShooter = frc::SmartDashboard::GetNumber("Shooter/botSpeed",40.0);

    // Velocity of the shooter wheels
    double d_topShooter = 22500;
    double d_botShooter = 22500;

    // Distance to the target in ft
    double distance = 15;

    if(Robot::m_subLimelight.GetTarget()){
       distance = Robot::m_subLimelight.GetDistanceToTarget();
       if(distance < 12.75 ){
         d_botShooter = 472.73 * distance * distance - 10906.06 * distance + 85044.47;
         d_topShooter = d_botShooter;
       }
       if(distance > 12.75 ){
         d_botShooter = 308.56 * distance + 18055.62;
         d_topShooter = d_botShooter;

       }
       
    }
   
    
    Robot::m_subShooter.SpinUpWheels( d_topShooter, d_botShooter );
    Robot::m_subMagazine.intakeShootMode = 1;
}

// Make this return true when this Command no longer needs to run execute()
bool CmdSpinShooterWheels::IsFinished() { 
    return true;
    
     }

// Called once after isFinished returns true
void CmdSpinShooterWheels::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdSpinShooterWheels::Interrupted() {}
