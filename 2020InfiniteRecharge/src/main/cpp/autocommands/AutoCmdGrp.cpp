/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*      Infinite Recharge 2020     */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "autocommands/AutoCmdGrp.h"

AutoCmdGrp::AutoCmdGrp() {
  // CommandGroup::AddSequential(new CmdCargoTilt(true));
  CommandGroup::AddSequential(new AutoCmdDrive());
  CommandGroup::AddSequential(new AutoCmdTurn());
  
}
