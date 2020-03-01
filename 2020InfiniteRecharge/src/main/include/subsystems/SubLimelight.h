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

#include <frc/commands/Subsystem.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

class SubLimelight : public frc::Subsystem {
 public:
  SubLimelight();
  void InitDefaultCommand() override;
  
  /**
     Get whether or not limelight has a target
    */
  bool GetTarget();

  /**
     Get horizontal Offset from Crosshair to target
    */
  double GetHorizontalOffset();

  /** 
     Get the distance from the target
     
     d = (h2-h1) / tan(a1+a2)

     d = distance from camera to target on horizontal plane
     h1 = the height of the camera from the ground
     h2 = the height of the center of the target
     a1 = the angle of the camera with respect to ground
     a2 = the angle of the target with respect to the camera ( limelight will give this angle "ty" from network tables)

    */
  double GetDistanceToTarget();

  /**
      Get the skew of the target
    */
  double GetSkew();

  /**
     Get the camera mounting angle THIS IS WRONG! NEEDS WORK ON EQUATION!
     
     d = (h2-h1) / tan(a1+a2)

     d = distance from camera to target on horizontal plane
     h1 = the height of the camera from the ground
     h2 = the height of the center of the target
     a1 = the angle of the camera with respect to ground
     a2 = the angle of the target with respect to the camera ( limelight will give this angle "ty" from network tables)

   */
  double GetCameraMountAngle(double distance);

  /**
     Set the Limelight LED state.
        
    0 - Use the LED Mode set in the current pipeline
    1 - Force LEDS off
    2 - Force LEDs to blink
    3 - Force LEDs on
   
    @param mode the mode to set for the LEDs
   */
  void SetLEDState(int mode);

  /** Set the Limelight camera mode.
    
    0 - Use Vision processing
    1 - Use Limeligt as Driver Camera (Increases exposure, disables vision processing)
   
    @param mode the mode to set for the Camera
  */
  void SetCameraMode(int mode);

  /** Select the vision pipline to use for targeting.
    
    0 - 9 Vision pipeline to use
    
    @param pipeline the pipeline to select for the vision targeting
  */
  void SelectPipeline(int pipeline);
  
  /** Select limelight's streaming mode.
    
    0 - Standard Side-by-Side stream if a webcam is attached to limelight.
    1 - PiP Main - The secondary camera stream is placed in the lower-right corner of the primary camera stream
    2 - PiP Secondary - The primary camera stream is placed in the lower-right corner of the secondary camera stream
    
    @param mode the streaming mode selected
  */
  void SelectStreamMode(int mode);
  
  /** Select limelight's snapshot mode.
    
    0 - Stop taking snapshots.
    1 - Take two snapshots per second
    
    @param mode the streaming mode selected
  */
  void SelectSnapshotMode(int mode);

 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  
  //nt::NetworkTableInstance::GetDefault().GetTable("limelight")->GetNumber("<variablename>",0.0);

  std::shared_ptr<NetworkTable> tblLimelight = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
};
