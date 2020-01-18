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

  driverController_button_x->WhenPressed(new CmdShoot());
  driverController_button_y->WhenPressed(new CmdStopShoot());
}
