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
  
  
  auxController_button_select->WhenPressed(new CmdDisengageClimber());
  auxController_button_start->WhenPressed(new CmdEngageClimber());
  auxController_button_lbump->WhenPressed(new CmdLifterUp());
  auxController_button_lbump->WhenReleased(new CmdLifterStop());
  auxController_button_rbump->WhenPressed(new CmdLifterDown());
  auxController_button_rbump->WhenReleased(new CmdLifterStop());

  // Shooter buttons
  spinShooter->WhileHeld(new CmdGrpPrepShooter());
  stopShooter->WhenPressed(new CmdGrpHaltShooter());


  // Intake buttons
  //driverController_button_y->WhenPressed(new CmdIntake());
  //runIntake->WhenPressed(new CmdIntakeExtend());
  //runIntake->WhenReleased(new CmdIntakeRetract());
  //driverController_button_y->WhenReleased(new CmdStopIntake());

  driverController_button_y->WhenPressed(new CmdGrpIntake());
  driverController_button_y->WhenReleased(new CmdGrpStopIntake());

  // Color Wheel Buttons
  //auxController_button_b->WhileHeld(new CmdNumberSpin());
  //auxController_button_a->WhileHeld(new CmdColorSpin());
  auxController_button_y->WhenPressed(new CmdMagazineIndexBall());

  // Magazine buttons
  auxController_button_a->WhenPressed(new CmdMagazineDump());


  switchToShooterMode->WhenPressed(new CmdMagazineSwitchShooter());
  switchToIntakeMode->WhenPressed(new CmdMagazineSwitchIntake());
  indexMagazine->WhenPressed(new CmdGrpIndexBall());
  shootBall->WhenPressed(new CmdIndexToShooter());


  // These are used in the autonomous phase of play
  ib_autoPrepShooter->WhenPressed(new CmdGrpPrepShooter());
  ib_autoPrepShooter->WhenReleased(new CmdGrpHaltShooter());
  ib_autoShoot->WhenPressed(new CmdIndexToShooter());
  ib_autoDrive->WhenPressed(new AutoCmdDrive());
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
    if (Robot::m_subMagazine.GetBallCount() >= 0) {
    switchToShooterMode->SetPressed(false);
    switchToIntakeMode->SetPressed(true);
    }

  } else if (driverController_button_y->Get() == 1) {
    
    if (Robot::m_subMagazine.GetBallCount() >= 0) {
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

// This function is run during the Autonomous Periodic function of the Robot Code
void OI::PollAutonomous(){
        
  // Spin up shooter and stops shooter in autonomous mode
  if(Robot::m_subMagazine.GetBallCount() > 0) {  
    // Spin up shooter in auto mode
    ib_autoPrepShooter->SetPressed(true);
    // Check if the wheels are up to speed on the shooter
    if(Robot::m_subShooter.WheelsAtSpeed() == true){
      // If the wheels are up to speed shoot the ball
      ib_autoShoot->SetPressed(true);
    } else{
      // If the wheels are not up to speed wait until they are up to speed
      ib_autoShoot->SetPressed(false);
    }

  } else {
    // Shutdown the shooter
    ib_autoPrepShooter->SetPressed(false);
  }

  // If all the ball are shot drive off starting line
  if(Robot::m_subMagazine.GetBallCount() == 0){
    ib_autoDrive->SetPressed(true);
  }
}

// Increment the autonomous counter
void OI::AutoCounterInc(){
  m_autonomousCounter = m_autonomousCounter + 1;
}

// Decrement the autonomous counter
void OI::AutoCounterDec(){
  m_autonomousCounter = m_autonomousCounter - 1;
}

// Set the autonomous counter to a value
void OI::AutoCounterSet(int value){
  m_autonomousCounter = value;
}

