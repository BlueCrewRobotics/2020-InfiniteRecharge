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

  driverController_button_a->WhenPressed(new CmdSpinShooterWheels());
  driverController_button_a->WhenReleased(new CmdStopShoot());

  driverController_button_y->WhenPressed(new CmdIntake());
  driverController_button_y->WhenReleased(new CmdStopIntake());
  //driverController_button_y->ToggleWhenPressed(new CmdIntakeExtend()); CHANGE THIS TO WHEN PRESSED AND WHEN RELEASED EXTEND AND RETRACT

  auxController_button_b->WhileHeld(new CmdNumberSpin());
  auxController_button_a->WhileHeld(new CmdColorSpin());
}
