#include <Arduino.h>
#include "A4988.h"
#include "player.h"
#include "util.h"


/*TODO
  Implement a motor playing solution that works
  Make Motor Scheduler w/ cases
  Make everything into a struct and cleanup
*/



// here comes a bunch of 'useful' vars; dont mind
int count;
bool dir=0;
int del;

int use=180;
int tempo=120;
int oct=5;

/* int first[] = {e,d,c,d,e,e,e};
int second[] = {d,d,d,e,g,g};
int fourth[] = {e,d,d,e,d,c}; */


void setup() {
  devInit();
}
void loop() {
  oct=5;
  getData();
}



void note(int num,long dur) {
  del=(num*oct)/10;
  dir=!dir;
 digitalWrite(dirPin,dir);
  count=floor((dur*5*tempo)/del);
  for(int x = 0; x < count; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(del);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(del);
  }

}

void pa(int durp){
  int ker=floor(durp/100)*tempo;
delay(ker);
  
  }





//checks that only one note is pressed





/* int switchesToInt(){
  int sol = 0;
  for(int i = 0; i < 8; i++){
    if (switches[i] == true){
      sol += power(2,7-i);
    }
  }
  return sol;
}

int power(int num, int raise){
  int result = 1;
  for (int i = 0; i < raise; i++){
    result *= num;
  }
  return result;
} 

*/

