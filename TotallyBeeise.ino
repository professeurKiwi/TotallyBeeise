//TotallyBeeise.ino
//Main file of the Beeise connected hive project

//This multi-file project is organized as follow:
// · TotallyBeeise.ino is the main file, it contains the setup and loop functions
// · Configurations.hpp contains precompilation directives you can twist to enable/disable Serial prints and buzzer jingle
// · PIN.hpp contains series of define to map components and pins associations
// · For each different type of sensor, a file implements at least a setup function and a get function
// · The LoRa.cpp file contains functions to send collected data to TTN
// · The Buzzer.cpp file contains functions to control the buzzer

// This project is developed by:
// · Ouerfili Chaïma
// · Bouchard Paul
// · Garzella Matteo
// · Dubois Noé



//sensor files includes
#include "DS18B20_Sensor.hpp"
#include "DHT22_Sensor.hpp"
#include "Battery.hpp"
#include "Weight_Sensor.hpp"
#include "Lux_Sensor.hpp"
//other includes
#include "LoRa.hpp"
#include "Buzzer.hpp"
#include "Configurations.hpp"
#include "SwitchLoad.hpp"

//true if LoRaWan connection is established
bool connected = false;

//Represents the cycle period in seconds
int cyclePeriod = 600;

void setup()
{
  //setup Serial
  Serial.begin(115200);
  //setup switch load
  SetupSwitchLoad();
  //setup sensors
  SetupDS18B20();
  SetupDHT22();
  SetupBatteryMesurment();
  SetupWeightSensor();
  setupLux();
  //setup Buzzer
  SetupBuzzer();
  //setup Lora
  SetupLoRaWan();

  delay(2000);

  //If serials arn't enable, play jingle to signifiate setup phase is finished
  //cf Configurations.hpp

  PlayJingle();
}

void loop()
{
  //If chip isn't connected to LoRaWan, try to do so
  if(!connected)
  {
      connected = TryConnect();
      delay(1000);
  }
    
  if(connected)
  {
      
        

      //Get sensor values
      float tmpIn1 = GetDS18B20Temperature(0);
      float tmpIn2 = GetDS18B20Temperature(1);
      float tmpIn3 = GetDHT22Temperature(0);
      float tmpOut = GetDHT22Temperature(1);

      float humidityIn = GetHumidity(0);
      float humidityOut = GetHumidity(1);

      float batteryVoltage = GetBatteryVoltage();

      float lux = getLux();

      float weight = GetWeight();
      if(weight < 0)
        weight = 0;

      //Print sensor values to Serial monitor. 
      //Please note that Configurations.hpp value can replace all print and println instructions by empty lines,
      //to avoid power lost
      print("Temperatures intérieures: "); 
      print(tmpIn1); print(" "); 
      print(tmpIn2); print(" "); 
      print(tmpIn3); print("\n"); 
      print("Temperature extérieure: "); print(tmpOut); print("\n"); 
      print("Humidité intérieure: "); print(humidityIn); print("\n");
      print("Humidité extérieure: "); print(humidityOut); print("\n");
      print("Voltage de la batterie: "); print(batteryVoltage); print("\n");
      print("Poids: "); print(weight); print("\n");
      print("lux: "); print(lux); print("\n");

      //send informations to TTN, and check if connection is lost.
      connected = SendInformations(tmpIn1, tmpIn2, tmpIn3, tmpOut, humidityIn, humidityOut, batteryVoltage, weight, lux);

      delay(7500);//receive message span
      //Get downlink message to configure the cycle period.
      int dlm = GetDownlinkMessage();
      if(dlm >= 8 )
      {
          print("Downlink message changed cycle period: "); print(dlm); println("sec");
          cyclePeriod = dlm;
          PlayJingle();
      }
  }

  SetPower(false);
  
  if(!ENABLE_SERIAL)
    LowPower.deepSleep(cyclePeriod * 1000 - 7500); //go into sleep mode until next cycle
  else
    delay(cyclePeriod * 1000 - 7500);

  SetPower(true);
}