//LoRa.cpp
//cf LoRa.hpp
#include "LoRa.hpp"

//Modem object
LoRaModem modem;
//app values
String appEui = "1691691691691691";
String appKey = "7F66E91117837596544AC1D184DC93D0";

//if this value goes too high, connection is concidered broken
int err_count; 

void SetupLoRaWan()
{
  modem.begin(EU868);
}

bool TryConnect()
{
  println("Connection trial");
  int ret = modem.joinOTAA(appEui, appKey);
  if(ret)
  {
    modem.minPollInterval(60);
    modem.dataRate(5);
    println("Connected");
    err_count = 0;
    PlayJingle();
    return true;
  }
  println("Connection failure");
  return false;
}

bool SendInformations(float tmpIn1, float tmpIn2, float tmpIn3, float tmpOut,
                      float humidityIn, float humidityOut,
                      float batteryVoltage, float weight, float lux)
{
  modem.beginPacket();
  modem.write((short)(tmpIn1 * 100));
  modem.write((short)(tmpIn2 * 100));
  modem.write((short)(tmpIn3 * 100));
  modem.write((short)(tmpOut * 100));
  modem.write((short)(humidityIn * 100));
  modem.write((short)(humidityOut * 100));
  modem.write((short)(batteryVoltage * 100));
  modem.write((short)(weight * 100));
  modem.write((short)(lux * 100));
  int err =  modem.endPacket();
  if ( err <= 0 ) {
      print("Error : ");
      println(err);

      err_count++;
      /*if ( err_count > 5 ) 
      {
        return false;
      }*/
        
  }
  return true;
}

int GetDownlinkMessage()
{
  int ret;

  if (!modem.available())
    return -1;

  ret = (char)modem.read();

  if (!modem.available())
    return -1;
  
  ret |= ((char)modem.read() << 8);

  return ret;
  
  
}