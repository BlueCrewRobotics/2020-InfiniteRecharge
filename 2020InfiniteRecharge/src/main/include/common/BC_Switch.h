/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                        Infinite Recharge 2020                              */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#include "frc/DigitalInput.h"
#include "frc/Counter.h"

class BC_Switch {

public:
  BC_Switch(int input);
  bool GetSwitchState();

private:
  frc::DigitalInput *ptr_digitalInput = nullptr;
  frc::Counter *ptr_Counter = nullptr;
};