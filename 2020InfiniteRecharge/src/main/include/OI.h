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


#include "commands/CmdSwitchGear.h"
//#include "commands/CmdIndexToShooter.h"
#include "commands/CmdStopShoot.h"
#include "frc/buttons/JoystickButton.h"
#include "frc/Joystick.h"
#include "frc/DigitalInput.h"
#include "frc/buttons/InternalButton.h"

//#include <frc/WPILib.h>
#include "RobotMap.h"
#include "commands/CmdIntake.h"
#include "commands/CmdStopIntake.h"
#include "commands/CmdIntakeExtend.h"
#include "commands/CmdIntakeRetract.h"
#include "commands/CmdColorSpin.h"
#include "commands/CmdNumberSpin.h"
//#include "commands/CmdMagazineSwitchShooter.h"
//#include "commands/CmdMagazineSwitchIntake.h"
#include "commands/CmdIndexToShooter.h"
#include "commands/CmdMagazineIndexBall.h"
#include "commands/CmdMagazineDecBall.h"
//#include "commands/CmdMagazineDump.h"
#include "commands/CmdEngageClimber.h"
#include "commands/CmdDisengageClimber.h"
#include "commands/CmdLifterUp.h"
#include "commands/CmdLifterStop.h"
#include "commands/CmdLifterDown.h"
#include "commands/CmdGrpIndexBall.h"

class OI {
 public:
  OI();
  void PollController();
  void PollMagazine();
  void PollAutonomous();
  /** Increment the autonomous counter
   */
  void AutoCounterInc();
  /** Increment the autonomous counter
   */
  void AutoCounterDec();
  /** Set the autonomous counter
   * 
   * @param value to set the counter
   */
  void AutoCounterSet(int value);

  //void PollController();
  bool m_bSelector = false;

  // Setup driver controller
  frc::Joystick *driverController = new frc::Joystick(DRIVER_CONTROLLER);
  // Setup buttons on the driver controller, change the name to fit the command
  frc::JoystickButton *driverController_button_a = new frc::JoystickButton(driverController, BUTTON_A); // Spinup wheels and aquire target from limelight
  frc::JoystickButton *driverController_button_b = new frc::JoystickButton(driverController, BUTTON_B); // Low gear mode
  frc::JoystickButton *driverController_button_x = new frc::JoystickButton(driverController, BUTTON_X); // Shoot the ball
  frc::JoystickButton *driverController_button_y = new frc::JoystickButton(driverController, BUTTON_Y); // Intake ball
  frc::JoystickButton *driverController_button_lbump = new frc::JoystickButton(driverController, BUTTON_L_BUMP); // Not Used
  frc::JoystickButton *driverController_button_rbump = new frc::JoystickButton(driverController, BUTTON_R_BUMP); // Used in gear shifting
  frc::JoystickButton *driverController_button_select = new frc::JoystickButton(driverController, BUTTON_SELECT); // Toggle Shooter between manual/auto mode 
  frc::JoystickButton *driverController_button_start = new frc::JoystickButton(driverController, BUTTON_START); // Not Used
  frc::JoystickButton *driverController_button_l3 = new frc::JoystickButton(driverController, BUTTON_L3); // Not Used
  frc::JoystickButton *driverController_button_r3 = new frc::JoystickButton(driverController, BUTTON_R3); // Not Used
  // LEFT TRIGGER // Drive Backwards
  // RIGHT TRIGGER // Drive Forwards
  // LEFT STICK LEFT // Turn Left
  // LEFT STICK RIGHT // Turn Right

  // Setup aux controller
  frc::Joystick *auxController = new frc::Joystick(AUX_CONTROLLER);
  // Setup buttons on the aux controller, change the names to fit the command
  frc::JoystickButton *auxController_button_a = new frc::JoystickButton(auxController, BUTTON_A); // 
  frc::JoystickButton *auxController_button_b = new frc::JoystickButton(auxController, BUTTON_B); 
  frc::JoystickButton *auxController_button_x = new frc::JoystickButton(auxController, BUTTON_X); 
  frc::JoystickButton *auxController_button_y = new frc::JoystickButton(auxController, BUTTON_Y); 
  frc::JoystickButton *auxController_button_lbump = new frc::JoystickButton(auxController, BUTTON_L_BUMP); 
  frc::JoystickButton *auxController_button_rbump = new frc::JoystickButton(auxController, BUTTON_R_BUMP); 
  frc::JoystickButton *auxController_button_select = new frc::JoystickButton(auxController, BUTTON_SELECT); 
  frc::JoystickButton *auxController_button_start = new frc::JoystickButton(auxController, BUTTON_START); 
  frc::JoystickButton *auxController_button_l3 = new frc::JoystickButton(auxController, BUTTON_L3); 
  frc::JoystickButton *auxController_button_r3 = new frc::JoystickButton(auxController, BUTTON_R3); 


  // Internal buttons used as triggers for automation.  See OI::Checker for
  // pressing and releasing buttons
    frc::InternalButton *runIntake = new frc::InternalButton();
    frc::InternalButton *stopIntake = new frc::InternalButton();
    

    frc::InternalButton *spinShooter = new frc::InternalButton();
    frc::InternalButton *stopShooter = new frc::InternalButton();



    frc::InternalButton *indexMagazine = new frc::InternalButton();
    frc::InternalButton *shootBall = new frc::InternalButton();
    frc::InternalButton *switchToIntakeMode = new frc::InternalButton();
    frc::InternalButton *switchToShooterMode = new frc::InternalButton();

    frc::InternalButton *ib_autoPrepShooter = new frc::InternalButton();
    frc::InternalButton *ib_autoShoot = new frc::InternalButton();
    frc::InternalButton *ib_autoDrive = new frc::InternalButton();
    


    private:
        bool testShootLock = false;
        int m_autonomousCounter = 0;
};
