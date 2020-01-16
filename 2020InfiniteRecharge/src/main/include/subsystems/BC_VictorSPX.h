/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include <ctre/Phoenix.h>

class BC_VictorSPX : public virtual frc::SpeedController {

public:
  BC_VictorSPX(int device);
  void Set(double speed);
  void PIDWrite(double output);
  double Get() const;
  void SetInverted(bool isInverted);
  bool GetInverted() const;
  void Disable();
  void StopMotor();

  VictorSPX *ptr_VictorSPX = nullptr;

private:
  double m_dSpeed = 0;
};
