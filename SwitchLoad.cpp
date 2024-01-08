#include "SwitchLoad.hpp"


void SetupSwitchLoad()
{
  pinMode(DONE_PIN, OUTPUT);
  pinMode(DELAY_PIN, OUTPUT);
}

void SetPower(bool on)
{
  if(on)
  {
    digitalWrite(DELAY_PIN, HIGH);
    delay(1200);
    digitalWrite(DELAY_PIN, LOW);
  }
  else
  {
    digitalWrite(DONE_PIN, HIGH);
    delay(50);
    digitalWrite(DONE_PIN, LOW);
  }
}