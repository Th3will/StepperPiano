#include <Arduino.h>
//#include "A4988.h "
#include "player.h"
#include "util.h"


/*TODO
  Implement a motor playing solution that works
  Make Motor Scheduler w/ cases
  Make everything into a struct and cleanup
*/



// here comes a bunch of 'useful' vars; dont mind
int count;


int oct=5;

Player motors = Player();
inpProc keyb = inpProc(); 


void setup() {
  motors.devInit();
}
void loop() {
  oct=5;
  keyb.GetData();
  keyb.ByteFlips();
  //find which keys are pressed and first pressed goes into first motor and second in second and so on
  
}



