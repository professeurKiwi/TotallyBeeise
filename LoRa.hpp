//LoRa.hpp
//Contains functions to send data via LoRaOne
#ifndef LORA
#define LORA

#include "MKRWAN_Protected.hpp"
#include "Configurations.hpp"
#include "Buzzer.hpp"


//Call once at project start
void SetupLoRaWan();
//Try to connect to TTN via OTAA protocol. Returns true if connection is established, false otherwise.
bool TryConnect(); 

//Send all sensor informations to TTN via LoRaWan Connection, returns false if connection is broken.
bool SendInformations(float tmpIn1, float tmpIn2, float tmpIn3, float tmpOut, float humidityIn, float humidityOut, float batteryVoltage, float weight, float lux);

int GetDownlinkMessage();

#endif