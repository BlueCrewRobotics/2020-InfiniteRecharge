/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once
#include <frc/commands/CommandGroup.h>
#include "commands/CmdIndexToShooter.h"
#include "autocommands/AutoCmdDrive.h"
#include "autocommands/AutoCmdTurn.h"

class AutoCmdGrp : public frc::CommandGroup {
public:
  AutoCmdGrp();
};
