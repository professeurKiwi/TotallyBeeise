//DHT22_Sensor.cpp
//cf DHT22_Sensor.hpp

#include "DHT22_Sensor.hpp"

DHT dht0(DHT22_0_PIN, DHT22);
DHT dht1(DHT22_1_PIN, DHT22);

void SetupDHT22()
{
  dht0.begin();
  dht1.begin();
}

float GetDHT22Temperature(int id)
{
  switch(id)
  {
    case 0:
      return dht0.readTemperature();
    case 1:
      return dht1.readTemperature();
  }
}

float GetHumidity(int id)
{
  switch(id)
  {
    case 0:
      return dht0.readHumidity();
    case 1:
      return dht1.readHumidity();
  }
}