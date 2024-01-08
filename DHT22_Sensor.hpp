//DHT22_Sensor.hpp
//Contains functions to read Humidity and Temperature values from DHT22 sensors

#ifndef DHT22_Sensor
#define DHT22_Sensor

#include "PIN.hpp"
#include <DHT.h>
#include <DHT_U.h>

//Call once at project start
void SetupDHT22();

//Returns the temperature value read by DHT22 number <id> (0 or 1 as there are 2 DHT22 sensors)
float GetDHT22Temperature(int id);
//Returns the humidity value read by DHT22 number <id> (0 or 1 as there are 2 DHT22 sensors)
float GetHumidity(int id);


#endif