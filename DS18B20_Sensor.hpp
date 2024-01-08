//DS18B20_Sensor.hpp
//Contains functions to read Temperature values from DS18B20 sensors
#ifndef DS18B20_Sensor
#define DS18B20_Sensor

#include "PIN.hpp"
#include <OneWire.h>
#include <DallasTemperature.h>

//Call once at project start
void SetupDS18B20();

//Returns the temperature value read by DS18B20 number <id> (0 or 1 as there are 2 DS18B20 sensors)
float GetDS18B20Temperature(int id);

#endif