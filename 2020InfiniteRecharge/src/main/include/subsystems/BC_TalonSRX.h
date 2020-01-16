/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/
/*     Blue Crew Robotics #6153    */
/*         Deep Space 2019         */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-*/

#pragma once

#include <ctre/Phoenix.h>
#include "RobotMap.h"
class BC_TalonSRX : public virtual frc::SpeedController {

	public: 
		BC_TalonSRX(int device);

		// Overides for the SpeedController class
		void Set(double speed);
		void PIDWrite(double output);
		double Get() const;
		void SetInverted(bool isInverted);
		bool GetInverted() const;
		void Disable();
		void StopMotor();
		void SetGear(bool gear);
		bool GetGear() const;
		void SetMaxSpeed(double maxSpeed);
		double GetMaxSpeed();

		// Added calls
		int GetCtrlLoopError();
		double GetCtrlLoopTarget();


		TalonSRX* ptr_talonSRX = nullptr;  
	private:
		double m_dSpeed = 0;
		bool m_bSelectedGear = 0;
		int m_iCount;
		double m_dMaxSpeed = VELOCITY_SP_MAX_LG;

};
