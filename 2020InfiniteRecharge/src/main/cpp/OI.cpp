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

#include "OI.h"
#include "Robot.h"

OI::OI() {
  // Process operator interface input here.

  driverController_button_rbump->ToggleWhenPressed(new CmdSwitchGear());

  driverController_button_x->WhenPressed(new CmdSpinShooterWheels());
  
  driverController_button_x->WhenReleased(new CmdStopShoot());

  driverController_button_a->WhenPressed(new CmdIntake());
  driverController_button_a->WhenReleased(new CmdStopIntake());

  driverController_button_a->ToggleWhenPressed(new CmdIntakeExtend());
  driverController_button_start->WhileHeld(new CmdNumberSpin());
  driverController_button_b->WhileHeld(new CmdColorSpin());
}
