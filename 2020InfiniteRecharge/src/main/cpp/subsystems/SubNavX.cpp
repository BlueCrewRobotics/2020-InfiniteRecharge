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

#include "subsystems/SubNavX.h"
#include "Robot.h"
#include "RobotMap.h"
#include "commands/CmdNavRead.h"

SubNavX::SubNavX() : frc::Subsystem("SubNavX") {}

void SubNavX::InitDefaultCommand() {
  // Set the default command for a subsystem here.
   SetDefaultCommand(new CmdNavRead());
}
void SubNavX::GetNavValues(){
        frc::SmartDashboard::PutBoolean( "IMU_Connected",        ahrs->IsConnected());
        frc::SmartDashboard::PutNumber(  "IMU_Yaw",              ahrs->GetYaw());
        frc::SmartDashboard::PutNumber(  "IMU_Pitch",            ahrs->GetPitch());
        frc::SmartDashboard::PutNumber(  "IMU_Roll",             ahrs->GetRoll());
        frc::SmartDashboard::PutNumber(  "IMU_CompassHeading",   ahrs->GetCompassHeading());
        frc::SmartDashboard::PutNumber(  "IMU_Update_Count",     ahrs->GetUpdateCount());
        frc::SmartDashboard::PutNumber(  "IMU_Byte_Count",       ahrs->GetByteCount());
        frc::SmartDashboard::PutNumber(  "IMU_Timestamp",        ahrs->GetLastSensorTimestamp());

        /* These functions are compatible w/the WPI Gyro Class */
        frc::SmartDashboard::PutNumber(  "IMU_TotalYaw",         ahrs->GetAngle());
        frc::SmartDashboard::PutNumber(  "IMU_YawRateDPS",       ahrs->GetRate());

        frc::SmartDashboard::PutNumber(  "IMU_Accel_X",          ahrs->GetWorldLinearAccelX());
        frc::SmartDashboard::PutNumber(  "IMU_Accel_Y",          ahrs->GetWorldLinearAccelY());
        frc::SmartDashboard::PutBoolean( "IMU_IsMoving",         ahrs->IsMoving());
        frc::SmartDashboard::PutNumber(  "IMU_Temp_C",           ahrs->GetTempC());
        frc::SmartDashboard::PutBoolean( "IMU_IsCalibrating",    ahrs->IsCalibrating());

        frc::SmartDashboard::PutNumber(  "Velocity_X",           ahrs->GetVelocityX() );
        frc::SmartDashboard::PutNumber(  "Velocity_Y",           ahrs->GetVelocityY() );
        frc::SmartDashboard::PutNumber(  "Displacement_X",       ahrs->GetDisplacementX() );
        frc::SmartDashboard::PutNumber(  "Displacement_Y",       ahrs->GetDisplacementY() );

        /* Display Raw Gyro/Accelerometer/Magnetometer Values                       */
        /* NOTE:  These values are not normally necessary, but are made available   */
        /* for advanced users.  Before using this data, please consider whether     */
        /* the processed data (see above) will suit your needs.                     */

        frc::SmartDashboard::PutNumber(  "RawGyro_X",            ahrs->GetRawGyroX());
        frc::SmartDashboard::PutNumber(  "RawGyro_Y",            ahrs->GetRawGyroY());
        frc::SmartDashboard::PutNumber(  "RawGyro_Z",            ahrs->GetRawGyroZ());
        frc::SmartDashboard::PutNumber(  "RawAccel_X",           ahrs->GetRawAccelX());
        frc::SmartDashboard::PutNumber(  "RawAccel_Y",           ahrs->GetRawAccelY());
        frc::SmartDashboard::PutNumber(  "RawAccel_Z",           ahrs->GetRawAccelZ());
        frc::SmartDashboard::PutNumber(  "RawMag_X",             ahrs->GetRawMagX());
        frc::SmartDashboard::PutNumber(  "RawMag_Y",             ahrs->GetRawMagY());
        frc::SmartDashboard::PutNumber(  "RawMag_Z",             ahrs->GetRawMagZ());
        frc::SmartDashboard::PutNumber(  "IMU_Temp_C",           ahrs->GetTempC());
        /* Omnimount Yaw Axis Information                                           */
        /* For more info, see http://navx-mxp.kauailabs.com/installation/omnimount  */
        AHRS::BoardYawAxis yaw_axis = ahrs->GetBoardYawAxis();
        frc::SmartDashboard::PutString(  "YawAxisDirection",     yaw_axis.up ? "Up" : "Down" );
        frc::SmartDashboard::PutNumber(  "YawAxis",              yaw_axis.board_axis );

        /* Sensor Board Information                                                 */
        frc::SmartDashboard::PutString(  "FirmwareVersion",      ahrs->GetFirmwareVersion());

        /* Quaternion Data                                                          */
        /* Quaternions are fascinating, and are the most compact representation of  */
        /* orientation data.  All of the Yaw, Pitch and Roll Values can be derived  */
        /* from the Quaternions.  If interested in motion processing, knowledge of  */
        /* Quaternions is highly recommended.                                       */
        frc::SmartDashboard::PutNumber(  "QuaternionW",          ahrs->GetQuaternionW());
        frc::SmartDashboard::PutNumber(  "QuaternionX",          ahrs->GetQuaternionX());
        frc::SmartDashboard::PutNumber(  "QuaternionY",          ahrs->GetQuaternionY());
        frc::SmartDashboard::PutNumber(  "QuaternionZ",          ahrs->GetQuaternionZ());


}

// Put methods for controlling this subsystem
// here. Call these from Commands.
