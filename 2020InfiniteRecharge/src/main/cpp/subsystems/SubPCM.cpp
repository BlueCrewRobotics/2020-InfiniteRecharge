/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "subsystems/SubPCM.h"

#include "RobotMap.h"

SubPCM::SubPCM() : frc::Subsystem("SubPCM") {}

void SubPCM::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void SubPCM::Configure() {
  compressor->SetClosedLoopControl(true);
  compressor->Start();
}
