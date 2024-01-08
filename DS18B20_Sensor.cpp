//DS18B20_Sensor.cpp
//cf DS18B20_Sensor.hpp
#include "DS18B20_Sensor.hpp"

//The OneWire objects corresponding to each sensor
OneWire oneWire(DS18B20_PIN);
//The actual sensor objects
DallasTemperature sensor(&oneWire);

void SetupDS18B20()
{
  sensor.begin();
}

float GetDS18B20Temperature(int id)
{
  sensor.requestTemperatures();
  sensor.getTempCByIndex(id);
}