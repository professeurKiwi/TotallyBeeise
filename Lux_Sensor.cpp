#include "Lux_Sensor.hpp"

void setupLux()
{
  Wire.begin();
}

float getLux()
{
  uint8_t reg = 0x10;
  Wire.beginTransmission(adress);
  Wire.write(&reg, 1);
  if(Wire.endTransmission() != 0)
  {
      println("EndTranmission...");
      return 0;
  }
    
  delay(20);
  Wire.requestFrom(adress, 2);
  return (float(Wire.read() << 8 | Wire.read())/1.2);
}
