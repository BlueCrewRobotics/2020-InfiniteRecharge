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
  driverController_button_rbump->ToggleWhenPressed(new CmdSwitchGear());
  
  
  auxController_button_select->WhenPressed(new CmdDisengageClimber());
  auxController_button_start->WhenPressed(new CmdEngageClimber());
  auxController_button_lbump->WhenPressed(new CmdLifterUp());
  auxController_button_lbump->WhenReleased(new CmdLifterStop());
  auxController_button_rbump->WhenPressed(new CmdLifterDown());
  auxController_button_rbump->WhenReleased(new CmdLifterStop());
  auxController_button_y->WhenPressed(new CmdMagazineIndexBall());

  // Intake buttons
  //driverController_button_y->WhenPressed(new CmdIntake());
  //runIntake->WhenPressed(new CmdIntakeExtend());
  //runIntake->WhenReleased(new CmdIntakeRetract());
  //driverController_button_y->WhenReleased(new CmdStopIntake());

  //driverController_button_y->WhenPressed(new CmdGrpIntake());
  //driverController_button_y->WhenReleased(new CmdGrpStopIntake());

  // Color Wheel Buttons
  //auxController_button_b->WhileHeld(new CmdNumberSpin());
  //auxController_button_a->WhileHeld(new CmdColorSpin());


  // Magazine buttons
  //auxController_button_a->WhenPressed(new CmdMagazineDump());


  //switchToShooterMode->WhenPressed(new CmdMagazineSwitchShooter());
  //switchToIntakeMode->WhenPressed(new CmdMagazineSwitchIntake());

  // Intake button
  runIntake->WhenPressed(new CmdGrpIntake()); // CAM ADDED
  runIntake->WhenReleased(new CmdGrpStopIntake()); // CAM ADDED
  indexMagazine->WhenPressed(new CmdGrpIndexBall());

  // Shooter buttons
  spinShooter->WhileHeld(new CmdGrpPrepShooter());
  stopShooter->WhenPressed(new CmdGrpHaltShooter());
  shootBall->WhenPressed(new CmdMagazineIndexBall()); // LUCIEN JUST ADDED THIS



  // These are used in the autonomous phase of play
  ib_autoPrepShooter->WhileHeld(new CmdGrpPrepShooter());
  ib_autoPrepShooter->WhenReleased(new CmdGrpHaltShooter());
  ib_autoShoot->WhenPressed(new CmdIndexToShooter());
  ib_autoDrive->WhenPressed(new AutoCmdDrive());
}

void OI::PollController() {
  if (Robot::m_subMagazine.GetSensor() == false) {
      indexMagazine->SetPressed(true);
    }
    else {
      indexMagazine->SetPressed(false);
    }

  // Extends intake, retracts intake and indexes magazine
  if(driverController_button_y->Get() == 1) {
    runIntake->SetPressed(true);

  } 
  else {
    runIntake->SetPressed(false);
  }

  // Spins shooter and stops shooter and shoots ball
  if(driverController_button_a->Get() == 1) {
    spinShooter->SetPressed(true);
    stopShooter->SetPressed(false);
      if (driverController_button_x->Get() == 1) {
        shootBall->SetPressed(true);
      }   
      else {
        shootBall->SetPressed(false);
      }
  } else {
    spinShooter->SetPressed(false);
    stopShooter->SetPressed(true);
  }



}

// Checks break sensor and changes internal buttons to control Magazine
void OI::PollMagazine() {


/* Cam Removed
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
*/

  //if (Robot::m_subMagazine.intakeShootMode == 0) { // LUCIEN REMOVED THIS AND THE ELSE STATEMENT
/* Cam relocated to poll magazine
    if (Robot::m_subMagazine.GetSensor() == true) {
      indexMagazine->SetPressed(true);
    } else {
      indexMagazine->SetPressed(false);
    }
*/
/* Cam relocated in poll controller
  //} else {
    if (driverController_button_a->Get() == 1) {
      if (driverController_button_x->Get() == 1) {
      shootBall->SetPressed(true);
    } else {
      shootBall->SetPressed(false);
    }
    }
*/  //}
}

// This function is run during the Autonomous Periodic function of the Robot Code
void OI::PollAutonomous(){
   ib_autoDrive->SetPressed(false);

   if (Robot::m_Timer.Get() > 3) 
   {

      // Spin up shooter and stops shooter in autonomous mode
      if(Robot::m_subMagazine.GetBallCount() > 0) {  
        // Spin up shooter in auto mode
        ib_autoPrepShooter->SetPressed(true);
        // Check if the wheels are up to speed on the shooter
        if(Robot::m_subShooter.WheelsAtSpeed() == true && Robot::m_subLimelight.GetTarget()==true ){
          // If the wheels are up to speed shoot the ball
          if(Robot::m_subMagazine.GetBallCount() == 3 && Robot::m_Timer.Get() > 4) {
            ib_autoShoot->SetPressed(false);
            ib_autoShoot->SetPressed(true);
          } else if(Robot::m_subMagazine.GetBallCount() == 2 && Robot::m_Timer.Get() > 5) {
            ib_autoShoot->SetPressed(false);
            ib_autoShoot->SetPressed(true);
          } else if(Robot::m_subMagazine.GetBallCount() == 1 && Robot::m_Timer.Get() > 6) {
            ib_autoShoot->SetPressed(false);
            ib_autoShoot->SetPressed(true);
          }
          

        } else{
          // If the wheels are not up to speed wait until they are up to speed
          ib_autoShoot->SetPressed(false);
        }

      } else if(Robot::m_Timer.Get() > 9){
        // Shutdown the shooter
        ib_autoPrepShooter->SetPressed(false);
        ib_autoDrive->SetPressed(true);
      }

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

