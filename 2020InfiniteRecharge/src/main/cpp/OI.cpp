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

  // Drive Train buttons
  //driverController_button_rbump->ToggleWhenPressed(new CmdSwitchGear());
  
  

  // Shooter buttons
  spinShooter->WhileHeld(new CmdGrpPrepShooter());
  stopShooter->WhenPressed(new CmdGrpHaltShooter());


  // Intake buttons
  driverController_button_y->WhenPressed(new CmdIntake());
  runIntake->WhenPressed(new CmdIntakeExtend());
  runIntake->WhenReleased(new CmdIntakeRetract());
  driverController_button_y->WhenReleased(new CmdStopIntake());


  // Color Wheel Buttons
  auxController_button_b->WhileHeld(new CmdNumberSpin());
  auxController_button_a->WhileHeld(new CmdColorSpin());

  // Magazine buttons
  //driverController_button_lbump->WhenPressed(new CmdMagazineDump());
  driverController_button_lbump->WhenPressed(new CmdEngageClimber());
  driverController_button_rbump->WhenPressed(new CmdDisengageClimber());

  switchToShooterMode->WhenPressed(new CmdMagazineSwitchShooter());
  switchToIntakeMode->WhenPressed(new CmdMagazineSwitchIntake());
  indexMagazine->WhenPressed(new CmdMagazineIndexBall());
  shootBall->WhenPressed(new CmdIndexToShooter());


}

void OI::PollController() {
  
  // Extends and retracts intake
  if(driverController_button_y->Get() == 1) {
    runIntake->SetPressed(true);
  } else {
    runIntake->SetPressed(false);
  }
    
    // Spins shooter and stops shooter
  if(driverController_button_a->Get() == 1) {
    spinShooter->SetPressed(true);
    stopShooter->SetPressed(false);
  } else {
    spinShooter->SetPressed(false);
    stopShooter->SetPressed(true);
  }



}

// Checks break sensor and changes internal buttons to control Magazine
void OI::PollMagazine() {

  if (driverController_button_a->Get() == 1) {
    Robot::m_subMagazine.intakeShootMode = 1;
    if (Robot::m_subMagazine.ballCount > 0) {
    switchToShooterMode->SetPressed(false);
    switchToIntakeMode->SetPressed(true);
    }

  } else if (driverController_button_y->Get() == 1) {
    Robot::m_subMagazine.intakeShootMode = 0;
    if (Robot::m_subMagazine.ballCount > 0) {
      switchToShooterMode->SetPressed(true);
      switchToIntakeMode->SetPressed(false);
    }
    
  }

  if (Robot::m_subMagazine.intakeShootMode == 0) {
    if (Robot::m_subMagazine.sensors[0] == true) {
      indexMagazine->SetPressed(true);
    } else {
      indexMagazine->SetPressed(false);
    }

  } else {
    if (driverController_button_a->Get() == 1) {
      if (driverController_button_x->Get() == 1) {
      shootBall->SetPressed(true);
    } else {
      shootBall->SetPressed(false);
    }
    }
  }





}