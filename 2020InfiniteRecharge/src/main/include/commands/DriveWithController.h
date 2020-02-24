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

#pragma once

#include "Robot.h"

#include "OI.h"
#include "subsystems/SubDriveTrain.h"
#include "common/BC_TriggerCal.h"

#include <frc/commands/Command.h>

class DriveWithController : public frc::Command {
	public:
		DriveWithController();
		void Initialize() override;
		void Execute() override;
		bool IsFinished() override;
		void End() override;
		void Interrupted() override;

		BC_TriggerCal* m_rotationTriggerCalLeft = new BC_TriggerCal(true);
		BC_TriggerCal* m_rotationTriggerCalRight = new BC_TriggerCal(false);
		BC_TriggerCal* m_lbumpReverseTriggerCal = new BC_TriggerCal(true); 
		BC_TriggerCal* m_rbumpForwardTriggerCal = new BC_TriggerCal(false); 
};
