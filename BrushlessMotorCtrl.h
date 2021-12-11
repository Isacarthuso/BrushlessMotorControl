#pragma once
#include<map>
#include <vector>
#include"iocontrol.h"

#ifndef BRUSHEL_MOTOR_CONTROL

#endif BRUSHEL_MOTOR_CONTROL

std::map<int8_t, int8_t> const LookupTableEscTemperatureSensor{
	{1,67},
	{2,31},
	{3,56}
};

enum 
{
 MOTOR_1,
 MOTOR_2,
 MOTOR_3,
 MOTOR_4
};



class BrushlessMotorCtrl
{

  friend void dshot(const int& mtrottle, const int& motor);

  private:
	  uint8_t trottle_percm1, trottle_percm2, trottle_percm3, trottle_percm4;

	  std::vector<uint8_t> trottle_motor_perc;

	  std::vector<int> ThermoparSensor; //TODO: Check the temperature that ESC supportto define the type

	  std::vector<int> DriveTemperature;//TODO: Check the temperature that ESC supportto define the type

	  bool ValidateTrottleRequest(const uint8_t& trottlereq, const uint8_t& motor);

  public:
	  void WriteThrottle(const uint8_t trottleperc, const uint8_t motor);

	  int  Readtrottle( uint8_t motor );

	  int  ReadMotorTemperature( int motor );

	  int  ReadThermoparSensor( int sensor );

	  int  EscTemperature( int drive );

	  void SafetyTrottle( void );
};