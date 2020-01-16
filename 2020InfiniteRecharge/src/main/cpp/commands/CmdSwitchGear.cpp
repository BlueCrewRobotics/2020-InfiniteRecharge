/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "commands/CmdSwitchGear.h"

#include "Robot.h"

CmdSwitchGear::CmdSwitchGear() {
  // Use Requires() here to declare subsystem dependencies
  Requires(&Robot::m_subsystem);
}

// Called just before this Command runs the first time
void CmdSwitchGear::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdSwitchGear::Execute() {
  bool lGear = 0;
  bool rGear = 0;
  lGear = Robot::m_subDriveTrain.leftDriveMotor->GetGear();
  rGear = Robot::m_subDriveTrain.rightDriveMotor->GetGear();

  lGear = !lGear;
  rGear = !rGear;

  Robot::m_subDriveTrain.leftDriveMotor->SetGear(lGear);
  Robot::m_subDriveTrain.rightDriveMotor->SetGear(rGear);

  Robot::m_subPCM.ptr_GearSolenoid->Set(lGear);
}

// Make this return true when this Command no longer needs to run execute()
bool CmdSwitchGear::IsFinished() { return true; }

// Called once after isFinished returns true
void CmdSwitchGear::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CmdSwitchGear::Interrupted() {}
