//Buzzer.cpp
//cf Buzzer.hpp

#include "Buzzer.hpp"

//Pitch of jingle notes
int melody[] = {
  REST, REST, REST, NOTE_E5, 
  NOTE_CS5, NOTE_CS5, NOTE_B4,
  NOTE_CS5, NOTE_E5,  REST, REST
};
//Duration of jingle notes
int durations[] = {
  8, 8, 8, 12, 
  12, 4, 12,
  12, 4,  8, 8
};

void SetupBuzzer()
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void PlayJingle()
{
  if(ENABLE_SERIAL)
    return;

   int size = sizeof(durations) / sizeof(int);

  for (int note = 0; note < size; note++) {
    //to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    //to distinguish the notes, set a minimum time between them.
    //the note's duration + 30% seems to work well:
    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);

    //stop the tone playing:
    noTone(BUZZER_PIN);
  }
}