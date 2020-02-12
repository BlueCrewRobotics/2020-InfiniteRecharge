/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "frc/WPILib.h"// CHANGE THIS TO THE CLASS THAT NEEDS TO BE INCLUDED TO REDUCE COMPILE TIMES

class BC_Switch {

public:
  BC_Switch(int input);
  bool GetSwitchState();

private:
  frc::DigitalInput *ptr_digitalInput = nullptr;
  frc::Counter *ptr_Counter = nullptr;
};