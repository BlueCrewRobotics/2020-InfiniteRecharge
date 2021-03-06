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

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;

constexpr int DRIVER_CONTROLLER = 0;
constexpr int AUX_CONTROLLER = 1;

/*
   Game controller button and joystick addressing.
   Access in code by including RobotMap.h and using BUTTON_A
   */
constexpr int BUTTON_A = 1;
constexpr int BUTTON_B = 2;
constexpr int BUTTON_X = 3;
constexpr int BUTTON_Y = 4;
constexpr int BUTTON_L_BUMP = 5;
constexpr int BUTTON_R_BUMP = 6; // Drive gear sifting
constexpr int BUTTON_SELECT = 7;
constexpr int BUTTON_START = 8;
constexpr int BUTTON_L3 = 9;
constexpr int BUTTON_R3 = 10;

constexpr int AXIS_LX = 0; // Steer left/right
constexpr int AXIS_LY = 1;
constexpr int AXIS_L_TRIG = 2; // Forward driving
constexpr int AXIS_R_TRIG = 3; // Reverse driving
constexpr int AXIS_RX = 4;
constexpr int AXIS_RY = 5;

/*
   Motor Drive Talon and Victor addressing.
   Access in code by including RobotMap.h and using MOTOR_LEFT_MASTER
   */

constexpr int MOTOR_LEFT_MASTER = 1;
constexpr int MOTOR_RIGHT_MASTER = 2;
constexpr int MOTOR_LEFT_FOLLOWER = 3;
constexpr int MOTOR_RIGHT_FOLLOWER = 4;

// Continuous current limit for Talons in amps
constexpr int CONTINUOUS_CURRENT_LIMIT = 50;
// Peak current limit for the Talons in amps
constexpr int PEAK_CURRENT_LIMIT = 100;
// Peak current duration for Talons in ms
constexpr int DURATION_CURRENT_LIMIT = 50;

// Ramp Times for drive starting and stopping
constexpr double DRIVE_RAMP_TIME = 0.05;

// Maximum velocity in units/100ms
constexpr int VELOCITY_MAX = 12000;
constexpr int VELOCITY_SP_MAX_HG = 12000;  // Maximum velocity in actual high gear
constexpr int VELOCITY_SP_MAX_LG = 12000;  // Maximum velocity in actual low gear
constexpr int VELOCITY_SP_MAX_LL = 5000;   // Maximum velocity in low low virtual gear


// PID constants PID[0] Used for low speed right side
constexpr double RIGHT_KF_0 = 0.06;  // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
constexpr double RIGHT_KP_0 = 0.13;  // Kp = ((percent of output used for control)*1023) / Error
constexpr double RIGHT_KI_0 = 0.0;
constexpr double RIGHT_KD_0 = 0.0;

// PID constants PID[1] uesd for high speed left side
constexpr double RIGHT_KF_1 = 0.06; // 0.296
constexpr double RIGHT_KP_1 = 0.13;
constexpr double RIGHT_KI_1 = 0;
constexpr double RIGHT_KD_1 = 0;

// PID constants PID[0] Used for low speed right side
constexpr double LEFT_KF_0 = 0.06; // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
constexpr double LEFT_KP_0 = 0.13; // Kp = ((percent of output used for control)*1023) / Error
constexpr double LEFT_KI_0 = 0.0;
constexpr double LEFT_KD_0 = 0;

// PID constants PID[1] uesd for high speed left side
constexpr double LEFT_KF_1 = 0.06; // 0.32
constexpr double LEFT_KP_1 = 0.13;
constexpr double LEFT_KI_1 = 0;
constexpr double LEFT_KD_1 = 0;

// Bottom PCM CAN ID
constexpr int PCM_BOTTOM = 9;
constexpr int PCM_TOP = 8;

// Solenoid Mappings for bottom PCM
constexpr int BTM_GEARSHIFT = 0;  // Drive train gear shifter


// Shooter Configuration
constexpr int SHOOTER_TOP_ADDR = 5;
constexpr int SHOOTER_BTM_ADDR = 6;
constexpr int SHOOTER_TURRET_ADDR = 7;

// Motor for the color wheel
constexpr int COLOR_MOTOR = 8;

// Motor for the Magazine
constexpr int MAGAZINE_MOTOR = 12;

// Motor for the Intake
constexpr int INTAKE_MOTOR = 13;
// Solenoid for IntakeExtend
constexpr int INTAKE_SOLENOID = 1;

// PID constants PID[0] Used for Shooter
constexpr double SHOOTER_TOP_KF_0 = 0.01704; 
constexpr double SHOOTER_TOP_KP_0 = 0.023; //0.0191;  
constexpr double SHOOTER_TOP_KI_0 = 0.0;
constexpr double SHOOTER_TOP_KD_0 = 0.0;

constexpr double SHOOTER_BTM_KF_0 = 0.01704; 
constexpr double SHOOTER_BTM_KP_0 = 0.023; //0.0191;  
constexpr double SHOOTER_BTM_KI_0 = 0.0;
constexpr double SHOOTER_BTM_KD_0 = 0.0;

constexpr double TURRET_KF_0 = 3.0;
constexpr double TURRET_KP_0 = 1.0;
constexpr double TURRET_KI_0 = 0.0;
constexpr double TURRET_KD_0 = 0.0;

constexpr int TURRET_CRUISE_VELOCITY = 10;
constexpr int TURRET_ACCELERATION = 10;

constexpr bool TURRET_SOFT_LIMITS_ENABLE = true;  // Disable/Enable of soft limits
constexpr int TURRET_LEFT_SOFT_LIMIT = 150;      // Set the soft left limit
constexpr int TURRET_RIGHT_SOFT_LIMIT = -2150;      // Set the soft right limit

constexpr int TURRET_MAX_ENCODER = 150;          // The max the turret will turn in encoder values
constexpr int TURRET_MIN_ENCODER = -2150;          // The min the turret will turn in encoder values
constexpr int TURRET_ZERO_POSITION = 0;


// Color Sensor Cofiguration
constexpr int WHEEL_BLUE    = 0;
constexpr int WHEEL_RED     = 2;
constexpr int WHEEL_GREEN   = 1;
constexpr int WHEEL_YELLOW  = 3;
constexpr int WHEEL_NOMATCH = -1;



// IO values for the break switches
constexpr int BALL_DETECTOR = 0;
constexpr int BALL_POS_1 = 1;
constexpr int BALL_POS_2 = 2;
constexpr int BALL_POS_3 = 3;
constexpr int BALL_POS_4 = 4;

