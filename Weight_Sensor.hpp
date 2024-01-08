//Weight_Sensor.hpp
//Contains functions to read weight value
#ifndef WEIGHT_SENSOR
#define WEIGHT_SENSOR

#include <HX711.h>
#include "PIN.hpp"

//Call once at project start
void SetupWeightSensor();

//Returns weight value in kilos
float GetWeight();
//Returns weight value in kilos, sampleCnt define the numbre of samples on which to average
float GetWeight(int sampleCnt);


#endif