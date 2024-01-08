//Weight_Sensor.cpp
//cf Weight_Sensor.hpp
#include "Weight_Sensor.hpp"
#define STRUCTURE_WEIGHT 509

HX711 Sensor;

void SetupWeightSensor()
{
  Sensor.begin(LOADCELL_DOUT_PIN, LOADCELL_PSCK_PIN);
  Sensor.set_scale(-342.32);
}

float GetWeight()
{
  return GetWeight(10);
}

float GetWeight(int sampleCnt)
{
  if(Sensor.is_ready())
    return (Sensor.get_units(sampleCnt) - STRUCTURE_WEIGHT) / 100;
  else
    return -1;
}

