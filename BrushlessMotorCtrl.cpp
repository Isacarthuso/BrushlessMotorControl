

#include "BrushlessMotorCtrl.h"


bool BrushlessMotorCtrl::ValidateTrottleRequest(const uint8_t& trottlereq, const uint8_t& motor)
{
	return (motor <= 4 && motor >= 1) && (trottlereq <= 100 && trottlereq >= 0) ? true : false;
}

void BrushlessMotorCtrl::WriteThrottle( const uint8_t trottleperc, const uint8_t motor )
{
	if ( ValidateTrottleRequest( trottleperc, motor ) )
		trottle_motor_perc.insert( trottle_motor_perc.begin() + motor - 1, trottleperc );

	else
	{
		BrushlessMotorCtrl::SafetyTrottle();
     }
}

void BrushlessMotorCtrl::SafetyTrottle( void )
{
	for (auto i : trottle_motor_perc)
	{
		trottle_motor_perc.emplace_back( 15 );
		dshot( 15, i + 1 );
	}
}

int BrushlessMotorCtrl::Readtrottle( uint8_t motor )
{
	//if (motor)
		//return trottle_motor_perc.at(motor-1);
		return 0;
}

int BrushlessMotorCtrl::ReadMotorTemperature( int motor )
{
	return 0;
}

int BrushlessMotorCtrl::ReadThermoparSensor( int sensor )
{
	return 0;
}

int BrushlessMotorCtrl::EscTemperature( int drive )
{
	return 0;
}


