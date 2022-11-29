#include <Arduino.h>
//#include <cmath>
//#include "A4988.h "
#include "Motor.h"


/*TODO
  Implement a motor playing solution that works
  Make Motor Scheduler w/ cases
  Make everything into a struct and cleanup
*/

//Motor Initialization
Motor motor0 = Motor(8,9);
Motor motor1 = Motor(10,11);
Motor motor2 = Motor(12,13);

//Shift Register pins
const int load = 7;
const int clockIn = 6;
const int dataIn = 5;
const int clockEnablePin = 4;

//Shift Register Input
byte incoming;

// here comes a bunch of 'useful' vars; dont mind
int count;
int oct = 5;
int note;
bool dir=0;
const int use=180;
const int tempo=120;



void GetData(){
  //unsigned long t0 = micros();
  digitalWrite(load, LOW);
  delayMicroseconds(5);
  digitalWrite(load, HIGH);
  delayMicroseconds(5);

  // Get data from 74HC165
  digitalWrite(clockIn, HIGH);
  digitalWrite(clockEnablePin, LOW);
  incoming = shiftIn(dataIn, clockIn, LSBFIRST);
}

int twoPow(int x){
  int resu = 1;
  for(int i = 0; i < x; i++){
    resu *= 2;
  }
  return resu;
}

int findNote(int index = 0){
  for (index; index < 8; index++){
    if(!(incoming & twoPow(index))){
      return index;
    }
  }
  return -1;
}

void setup() {
  motor0.init();
  motor1.init();
  motor2.init();
  pinMode(dataIn,INPUT);
  pinMode(load,OUTPUT);
  pinMode(clockIn,OUTPUT);
  pinMode(clockEnablePin,OUTPUT);
  Serial.begin(9600);
  
  
}
void loop() {
  int time = millis();
  //find which keys are pressed and first pressed goes into first motor and second in second and so on
  GetData();
  note = findNote();
  motor0.play(note);
  motor1.play(note);
  motor2.play(note);
}


