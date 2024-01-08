//Battery.cpp
//cf Battery.hpp

#include "Battery.hpp"

void SetupBatteryMesurment()
{
  pinMode(BATTERY_MESURMENT_PIN, INPUT);
}

int GetBatteryCharge()
{
  return constrain(map(analogRead(BATTERY_MESURMENT_PIN), ANALOGIN_CUTOFF_VOLTAGE, ANALOGIN_MAX_VOLTAGE, 0, 100), 0, 100);
}

float GetBatteryVoltage()
{
  return (float)map(analogRead(BATTERY_MESURMENT_PIN), ANALOGIN_CUTOFF_VOLTAGE, ANALOGIN_MAX_VOLTAGE, 330, 550)/(float)100;
}