/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "common/BC_Switch.h"

BC_Switch::BC_Switch(int input) {

  ptr_digitalInput = new frc::DigitalInput(input);
  ptr_Counter = new frc::Counter(ptr_digitalInput->GetChannel());
}

bool BC_Switch::GetSwitchState() {
  if (ptr_Counter->Get() > 0) {
    ptr_Counter->Reset();
    return true;
  } else {
    return false;
  }
}
