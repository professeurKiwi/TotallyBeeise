#ifndef LUX_SENSOR_H
#define LUX_SENSOR_H

#include "Wire.h"
#include "PIN.hpp"
#include "MKRWAN_Protected.hpp"
#include "Configurations.hpp"

#define adress 0x23

void setupLux();
float getLux();

#endif