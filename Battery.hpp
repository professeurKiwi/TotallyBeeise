//Battery.hpp
//Contains functions to read Battery Charge
#ifndef BATTERY
#define BATTERY

#include "PIN.hpp"
#include "ArduinoLowPower.h"

//The Analogin value corresponding to the battery 100% charge state
#define ANALOGIN_MAX_VOLTAGE 1023
//The Analogin value corresponding to the battery 0% charge state
#define ANALOGIN_CUTOFF_VOLTAGE 731

//Call once at project start
void SetupBatteryMesurment();

//returns battery charge in purcentage
int GetBatteryCharge();

//returns battery voltage
float GetBatteryVoltage();

#endif