/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#include "subsystems/BC_VictorSPX.h"
#include "RobotMap.h"
#include <ctre/Phoenix.h>

BC_VictorSPX::BC_VictorSPX(int device) {

  BC_VictorSPX::ptr_VictorSPX = new VictorSPX(device);
}

void BC_VictorSPX::Set(double speed) {
  // speed = speed*VELOCITY_SP_MAX_LG;
  ptr_VictorSPX->Set(ControlMode::PercentOutput, speed);
  m_dSpeed = speed;
}

void BC_VictorSPX::PIDWrite(double output) {}

double BC_VictorSPX::Get() const { return m_dSpeed; }

void BC_VictorSPX::SetInverted(bool isInverted) {
  ptr_VictorSPX->SetInverted(isInverted);
}

bool BC_VictorSPX::GetInverted() const { return ptr_VictorSPX->GetInverted(); }

void BC_VictorSPX::Disable() {
  ptr_VictorSPX->SetNeutralMode(NeutralMode::Coast);
}

void BC_VictorSPX::StopMotor() {
  ptr_VictorSPX->SetNeutralMode(NeutralMode::Brake);
}
