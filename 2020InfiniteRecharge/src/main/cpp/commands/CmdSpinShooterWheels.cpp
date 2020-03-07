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
#include <iostream>
using namespace std;


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
    double d_topShooter = 25729;
    double d_botShooter = 25729;

    // Distance to the target in ft
    double distance = Robot::m_subLimelight.GetLimelightDistance();

    // Apply correlation equations of target distance to wheels speed
    if(Robot::m_subLimelight.GetTarget()==true){
       distance = Robot::m_subLimelight.GetDistanceToTarget();
       if(distance < 11.5 ){
         d_botShooter = 644.92 * distance * distance - 12548.17 * distance + 81259.57;
         d_topShooter = d_botShooter;
       }
       if(distance > 11.5 ){
         d_botShooter = 283.70 * distance + 16735;
         d_topShooter = d_botShooter;

       }
       // Set the limelight distance incase we losde the target
       Robot::m_subLimelight.SetLimelightDistance(distance);
      
    }
    // We don't have a target so use the last aquired limelight target
    else{
        distance = Robot::m_subLimelight.GetLimelightDistance();
        if(distance < 11.5 ){
          d_botShooter = 644.92 * distance * distance - 12548.17 * distance + 81259.57;
          d_topShooter = d_botShooter;
        }
        if(distance > 11.5 ){
          d_botShooter = 283.70 * distance + 16735;
          d_topShooter = d_botShooter;

        }
    
    }

    // Add offsets for wheels slowing upon launch
    d_botShooter = d_botShooter + 14000;
    d_topShooter= d_topShooter + 14000;

   std::cout << "Distance= " << distance << std::endl;
   std::cout << "Angle= " << Robot::m_subLimelight.GetCameraMountAngle(10.083) << std::endl;
   std::cout << "WheelSpeed= " << d_botShooter << std::endl;
   std::cout << " " << std::endl;

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
