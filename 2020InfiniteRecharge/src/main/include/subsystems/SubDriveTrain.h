/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include "BC_TalonSRX.h"
#include "BC_VictorSPX.h"
#include "RobotMap.h"
#include "frc/SpeedController.h"
#include <ctre/Phoenix.h>
#include <frc/WPILib.h>
#include <frc/commands/Subsystem.h>

class SubDriveTrain : public frc::Subsystem {

public:
  SubDriveTrain();
  void InitDefaultCommand() override;
  void Configure();
  void ConfigurePID();
  void Drive(double speed, double rotation);
  void DriveVelocityControl(double speed, double rotation);
  void SetRamp(double ramp);
  // void Set(double speed) ;

  // private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  /*
     WPI_TalonSRX* leftDriveMotor = new WPI_TalonSRX(MOTOR_LEFT_MASTER);
     WPI_TalonSRX* rightDriveMotor = new WPI_TalonSRX(MOTOR_RIGHT_MASTER);
     WPI_VictorSPX* leftFollowMotor = new WPI_VictorSPX(MOTOR_LEFT_FOLLOWER);
     WPI_VictorSPX* rightFollowMotor = new WPI_VictorSPX(MOTOR_RIGHT_FOLLOWER);
     */

  BC_TalonSRX *leftDriveMotor = new BC_TalonSRX(MOTOR_LEFT_MASTER);
  BC_TalonSRX *rightDriveMotor = new BC_TalonSRX(MOTOR_RIGHT_MASTER);

  BC_TalonSRX *leftFollowMotor = new BC_TalonSRX(MOTOR_LEFT_FOLLOWER);
  BC_TalonSRX *rightFollowMotor = new BC_TalonSRX(MOTOR_RIGHT_FOLLOWER);

  //		BC_VictorSPX* leftFollowMotor = new
  //BC_VictorSPX(MOTOR_LEFT_FOLLOWER); 		BC_VictorSPX* rightFollowMotor = new
  //BC_VictorSPX(MOTOR_RIGHT_FOLLOWER);

  /*
     BC_TalonSRX* leftDriveMotor = new BC_TalonSRX(MOTOR_LEFT_MASTER);
     BC_TalonSRX* rightDriveMotor = new BC_TalonSRX(MOTOR_RIGHT_MASTER);
     BC_VictorSPX* leftFollowMotor = new BC_VictorSPX(MOTOR_LEFT_FOLLOWER);
     BC_VictorSPX* rightFollowMotor = new BC_VictorSPX(MOTOR_RIGHT_FOLLOWER);
     */

  frc::DifferentialDrive *driveTrain = new frc::DifferentialDrive(*leftDriveMotor, *rightDriveMotor);
};
