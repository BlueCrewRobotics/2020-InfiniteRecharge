/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*      Infinite Recharge 2020     */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "autocommands/AutoCmdGrp.h"

AutoCmdGrp::AutoCmdGrp() {
  // CommandGroup::AddSequential(new CmdCargoTilt(true));
<<<<<<< HEAD
  CommandGroup::AddSequential(new AutoCmdDrive());
  CommandGroup::AddSequential(new AutoCmdTurn());
  
=======
  CommandGroup::AddSequential(new CmdIndexToShooter());
>>>>>>> parent of 7985dc0... Messed around with auto and magazine
}
