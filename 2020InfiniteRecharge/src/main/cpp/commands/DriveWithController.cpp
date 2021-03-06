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

// Driving with the controller

#include "commands/DriveWithController.h"
#include "iostream"

#include "Robot.h"

DriveWithController::DriveWithController() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subDriveTrain);
}

// Called just before this Command runs the first time
void DriveWithController::Initialize() {
  // Maybe add the Robot::m_subDriveTrain.Configure(); here to initialize,
  // because the Command will always be scheduled never end unless we do below
  // in the End() Robot::m_subDriveTrain.Drive(0,0);  Currently
  // Robot::m_subDriveTrain.Configure(); is run in the RobotInit() leaving there
  // for now
}

// Called repeatedly when this Command is scheduled to run
void DriveWithController::Execute() 
{
	double rotation = 0;
	////if(Robot::m_oi.driverController_button_a->Get() == 1){
		//nt::NetworkTableEntry ntTargetCenter;
		//auto ntinst = nt::NetworkTableInstance::GetDefault();
		//auto table = ntinst.GetTable("visionTuning");
		

		
		////if(Robot::m_subLimelight.GetTarget() == 1.0){

		
			//double d_targetCenter = 0; // frc::SmartDashboard::GetNumber("targetCenter",160);
			////double d_targetAngle = Robot::m_subLimelight.GetHorizontalOffset(); // frc::SmartDashboard::GetNumber("targetAngle", 0);
			////double d_gain = 0.65;

		
//		double d_targetCenter = nt::NetworkTableEntry::GetDouble("targetCenter");
		
		// Used to normalize from -1.0 to 1.0
		//rotation = (d_gain*(((29.8-d_targetCenter)/29.8) - (d_targetAngle/29.8)));
		////rotation = (-1*(d_targetAngle/29.8))*d_gain;
		//std::cout << rotation << std::endl;


		////if(rotation > 0){
		////	rotation = m_rotationTriggerCalLeft->GetCalibratedTrigger(rotation, 0.2, 0.01);
		////} 
		////if(rotation < 0){
		////	rotation = m_rotationTriggerCalRight->GetCalibratedTrigger(rotation*-1, 0.2, 0.01);
		////}
		//double vtape_offset = frc::SmartDashboard::GetNumber("VTape_Offset", 0.0);
		//double cameraWidth = frc::SmartDashboard::GetNumber("cameraWidth", 400);

		//rotation = (vtape_offset/2)/cameraWidth;
		////}
	////} else {
	  if( Robot::m_subDriveTrain.leftDriveMotor->GetGear() == false) {
		  rotation = Robot::m_oi.driverController->GetRawAxis(AXIS_LX)*1;         
	  }else{
		rotation = Robot::m_oi.driverController->GetRawAxis(AXIS_LX)*1;
	  }
	////}


	if (Robot::m_oi.driverController_button_b->Get()==1 || Robot::m_oi.driverController_button_y->Get()==1){
		Robot::m_subDriveTrain.leftDriveMotor->SetMaxSpeed(VELOCITY_SP_MAX_LL);
		Robot::m_subDriveTrain.rightDriveMotor->SetMaxSpeed(VELOCITY_SP_MAX_LL);
	}
	else{
		Robot::m_subDriveTrain.leftDriveMotor->SetMaxSpeed(VELOCITY_SP_MAX_LG);
		Robot::m_subDriveTrain.rightDriveMotor->SetMaxSpeed(VELOCITY_SP_MAX_LG);
	}
	double velocityReverse = m_lbumpReverseTriggerCal->GetCalibratedTrigger(Robot::m_oi.driverController->GetRawAxis(AXIS_L_TRIG),0.2,0.05);
	double velocityForward = m_rbumpForwardTriggerCal->GetCalibratedTrigger(Robot::m_oi.driverController->GetRawAxis(AXIS_R_TRIG),0.2,0.05);

	//double velocityReverse = Robot::m_oi.driverController->GetRawAxis(AXIS_L_TRIG);
	//double velocityForward = Robot::m_oi.driverController->GetRawAxis(AXIS_R_TRIG)*-1;




	if(Robot::m_oi.driverController->GetRawAxis(AXIS_L_TRIG) > 0){
		Robot::m_subDriveTrain.Drive(velocityReverse,rotation);
	}else{    
		Robot::m_subDriveTrain.Drive(velocityForward,rotation);
	}


	//if(Robot::m_oi.driverController_button_start->Get() == 1){
		//Robot::m_subDriveTrain.ConfigurePID();
	//}


}

// Make this return true when this Command no longer needs to run execute()
bool DriveWithController::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveWithController::End() {
  // Robot::m_subDriveTrain.Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveWithController::Interrupted() {}
