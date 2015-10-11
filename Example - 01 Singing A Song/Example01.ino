#include "application.h"

/*
Basically we have connected a buzzer and a clicker.
The main (infinite) loop checks when the clicker is currently pressed. If it is, invokes it's routing to play a song.
*/

// name the pins
#define BUTTONPIN D2
#define BUZZERPIN D1

int melody[] = {1908, 2551, 2551, 2273, 2551, 0, 2024, 1908}; //notes in the melody
int noteDurations[] = {4,8,8,4,4,4,4,4};                //note durations

void setup() {
  pinMode(BUTTONPIN, INPUT);    // set user key pin as input
}

void loop() {  
  if(digitalRead(BUTTONPIN) == 1){
      // if the button was pressed 
      playSong();
  }
}

void playSong(){
  // loop over each defined note in the array
  for( int thisNote = 0; thisNote < 8; thisNote++ ) {
    // get node duration
    int noteDuration = 1000 / noteDurations[thisNote];
    // play note
    tone(BUZZERPIN, melody[thisNote], noteDuration);
    // set a minimum time between notes
    int pauseBetweenNotes = noteDuration * 1.30;
    //delay for the while
    delay(pauseBetweenNotes);
    // explicitely stop the tone playing
    // not sure if it's really required
    // noTone(BUZZERPIN);     
  }
}
