/*
 * Ubunutu Core test program for wiringpi.
 * WiringPi Version tested: 2.46
 * Hardware used: Berryclip 6
 * Code from:
 * https://www.raspberrypi-spy.co.uk/2013/04/berryclip-6-led-board-testing-in-c/
 */

#include <wiringPi.h>
#include <stdlib.h>
 
int leds[6] = { 7, 0, 3, 12, 13, 14 };
int BUZZER = 10;
int BUTTON = 11;
void all_leds_off();
void init_pins();
 
int main (void) {
  //Check we have wiringPi
  if (wiringPiSetup () == -1 ) exit (1);
  init_pins();
  all_leds_off();
  for (;;) {
    if (digitalRead (BUTTON) == 1 ) {
      for (int i = 0; i < 6; i++) {
        digitalWrite (BUZZER,1);
        digitalWrite (leds[i],1);
        delay (50);
        digitalWrite (BUZZER,0);
        delay (450);
      }
      delay (1000);
      all_leds_off();
    }
    delay(50);
  }
  exit(0);
}
 
void init_pins() {
  //set leds as outputs...
  for (int i = 0; i < 6; i++) {
    pinMode(leds[i], OUTPUT);
  }
  // set buzzer as output...
  pinMode(BUZZER, OUTPUT);
 
  // set button as an input...
  pinMode(BUTTON, INPUT);
}
 
void all_leds_off() {
  for (int i = 0; i < 6; i++) {
    digitalWrite (leds[i],0);
  }
}
