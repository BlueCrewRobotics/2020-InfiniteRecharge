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

#include "subsystems/SubLimelight.h"

#include "RobotMap.h"

SubLimelight::SubLimelight() : frc::Subsystem("SubLimelight") {}

void SubLimelight::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

/**
 * Get whether or not limelight has a target
 */
bool SubLimelight::GetTarget() {
  if(tblLimelight->GetNumber("tv",0.0) < 1.0){
    return false;
  }
  return true;
  
}

  /**
     Get horizontal Offset from Crosshair to target
   */
  double SubLimelight::GetHorizontalOffset(){
    return tblLimelight->GetNumber("tx",0.0);

  }
  
  /**
     Get the distance from the target
     
     d = (h2-h1) / tan(a1+a2)

     d = distance from camera to target on horizontal plane
     h1 = the height of the camera from the ground
     h2 = the height of the center of the target
     a1 = the angle of the camera with respect to ground
     a2 = the angle of the target with respect to the camera ( limelight will give this angle "ty" from network tables)

    */
  double SubLimelight::GetDistanceToTarget(){
    double d = 0.0; // feet
    double h1 = 21.0/12; // feet
    double h2 = 98.25/12; // feet
    double a1 = 0.0; // degrees
    double a2 = tblLimelight->GetNumber("ty",0.0);    
    
    d = (h2-h1) / tan(a1 + a2);

    return d;

  }
 
   /**
      Get the skew of the target
    */
  double SubLimelight::GetSkew(){
    return tblLimelight->GetNumber("ts",0.0);

  }
  
  /**
     Get the camera mounting angle THIS IS WRONG! NEEDS WORK ON EQUATION!
     
     d = (h2-h1) / tan(a1+a2)

     d = distance from camera to target on horizontal plane
     h1 = the height of the camera from the ground
     h2 = the height of the center of the target
     a1 = the angle of the camera with respect to ground
     a2 = the angle of the target with respect to the camera ( limelight will give this angle "ty" from network tables)

   */
  double SubLimelight::GetCameraMountAngle(double distance){
    double d = distance;
    double h1 = 21.0/12; // inches
    double h2 = 98.25/12; // inches
    double a1 = 0.0; // degrees
    double a2 = tblLimelight->GetNumber("ty",0.0);
    
    a1 = 1/tan((((h2-h1)/tan(a2))-d));
    
    
    return a1;

  }

  /**
     Set the Limelight LED state.
        
    0 - Use the LED Mode set in the current pipeline
    1 - Force LEDS off
    2 - Force LEDs to blink
    3 - Force LEDs on
   
    @param mode the mode to set for the LEDs
   */
  void SubLimelight::SetLEDState(int mode){
    tblLimelight->PutNumber("ledMode",mode);

  }

  /** Set the Limelight camera mode.
    
    0 - Use Vision processing
    1 - Use Limeligt as Driver Camera (Increases exposure, disables vision processing)
   
    @param mode the mode to set for the Camera
  */
  void SubLimelight::SetCameraMode(int mode){
    tblLimelight->PutNumber("camMode",mode);

  }
  
  /** Select the vision pipline to use for targeting.
    
    0 - 9 Vision pipeline to use
    
    @param pipeline the pipeline to select for the vision targeting
  */
  void SubLimelight::SelectPipeline(int pipeline){
    tblLimelight->PutNumber("pipeline",pipeline);

  }

  /** Select limelight's streaming mode.
    
    0 - Standard Side-by-Side stream if a webcam is attached to limelight.
    1 - PiP Main - The secondary camera stream is placed in the lower-right corner of the primary camera stream
    2 - PiP Secondary - The primary camera stream is placed in the lower-right corner of the secondary camera stream
    
    @param mode the streaming mode selected
  */
  void SubLimelight::SelectStreamMode(int mode){
    tblLimelight->PutNumber("stream",mode);

  }

  /** Select limelight's snapshot mode.
    
    0 - Stop taking snapshots.
    1 - Take two snapshots per second
    
    @param mode the streaming mode selected
  */
  void SubLimelight::SelectSnapshotMode(int mode){
    tblLimelight->PutNumber("snapshot",mode);

  }
// Put methods for controlling this subsystem
// here. Call these from Commands.
