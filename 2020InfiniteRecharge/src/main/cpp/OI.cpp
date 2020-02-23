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

  spinShooter->WhenPressed(new CmdSpinShooterWheels());
  stopShooter->WhenPressed(new CmdStopShoot());


  
  runIntake->WhenPressed(new CmdIntake());
  stopIntake->WhenPressed(new CmdStopIntake());

  //driverController_button_y->ToggleWhenPressed(new CmdIntakeExtend()); CHANGE THIS TO WHEN PRESSED AND WHEN RELEASED EXTEND AND RETRACT

  auxController_button_b->WhileHeld(new CmdNumberSpin());
  auxController_button_a->WhileHeld(new CmdColorSpin());

  switchToShooterMode->WhenPressed(new CmdMagazineSwitchShooter());
  switchToIntakeMode->WhenPressed(new CmdMagazineSwitchIntake());
  indexMagazine->WhenPressed(new CmdMagazineIndexBall());
  shootBall->WhenPressed(new CmdShoot());


}

void OI::PollController() {
  
  if(driverController_button_y->Get() == 1) {
    runIntake->SetPressed(true);
    stopIntake->SetPressed(false);
  } else {
    runIntake->SetPressed(false);
    stopIntake->SetPressed(true);
  }
    
  if(driverController_button_a->Get() == 1) {
    spinShooter->SetPressed(true);
    stopShooter->SetPressed(false);
  } else {
    spinShooter->SetPressed(false);
    stopShooter->SetPressed(true);
  }



}

void OI::PollMagazine() {
  if (driverController_button_a->Get() == 1) {
    Robot::m_subMagazine.intakeShootMode = 1;
    switchToShooterMode->SetPressed(false);
    switchToIntakeMode->SetPressed(true);
  } else if (driverController_button_y->Get() == 1) {
    Robot::m_subMagazine.intakeShootMode = 0;
    switchToShooterMode->SetPressed(true);
    switchToIntakeMode->SetPressed(false);
  }

  if (Robot::m_subMagazine.intakeShootMode == 0) {
    if (Robot::m_subMagazine.sensors[0] == true) {
      indexMagazine->SetPressed(true);
    } else {
      indexMagazine->SetPressed(false);
    }

  } else {
    if (driverController_button_x->Get() == 1) {
      shootBall->SetPressed(true);
    } else {
      shootBall->SetPressed(false);
    }
  }
}