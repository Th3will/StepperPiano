#include <Arduino.h>
//#include <cmath>
//#include "A4988.h "
#include "Motor.h"


/*TODO
  Implement a motor playing solution that works
  Make Motor Scheduler w/ cases
  Make everything into a struct and cleanup
*/




// here comes a bunch of 'useful' vars; dont mind
int coun;
int oct = 5;int del;
bool dir=0;
const int use=180;
const int tempo=120;
const long dur = 35;

const int notes[8] = {2024, 1912, 1703, 1517, 1431, 1275, 1136, 1012};

//Motor pins; Left->Mid->Right
const int motorDir[3] = {8,10,12};
const int motorStep[3] = {9,11,13};
//cycles through during loop to schedule which motor


//Motor Initialization
void motorInit(){
  //motor right
    pinMode(motorStep[0],OUTPUT); 
    pinMode(motorDir[0],OUTPUT);
    //motor mid
    pinMode(motorStep[1],OUTPUT); 
    pinMode(motorDir[1],OUTPUT);
    //motor left
    pinMode(motorStep[2],OUTPUT); 
    pinMode(motorDir[2],OUTPUT);
}

//Key Initialization
void keyInit(){
    pinMode(0,INPUT_PULLUP);
    //pinMode(1,INPUT_PULLUP);
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    pinMode(4,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
    pinMode(6,INPUT_PULLUP);
    pinMode(7,INPUT_PULLUP);

}

//play music
void note(int num, int mtrID) {
  del=(notes[num]*oct)/10;
  digitalWrite(motorDir[mtrID],dir);
  //x in x*5*temp is duration in milliseconds
  coun=floor((dur*5*tempo)/del);
  for(int x = 0; x < coun; x++) {
    digitalWrite(motorStep[mtrID],HIGH);
    delayMicroseconds(del);
    digitalWrite(motorStep[mtrID],LOW);
    delayMicroseconds(del);
  }
  Serial.println("-----------------------------");
  Serial.println("detected note nextMotor");
  Serial.println(num);
  Serial.println("-----------------------------");
}

void setup() {
    motorInit();
    keyInit();
    Serial.begin(9600);
}

void loop() {
  int motorID = 0;
  for (int i = 0; i < 8; i++)
  {
    //check button pressed and hasn't already scheduled all other avai
    if(digitalRead(i)==LOW&&motorID < 3&&i!=1){
      note(i,motorID);
      Serial.println(" I'm not");
      motorID++;
    } else if(digitalRead(i)==LOW&&motorID < 3){
      Serial.println(digitalRead(i));
      Serial.println(" I'm SpEcIaL");
      delay(1000);
    } else if(digitalRead(i)==HIGH&&motorID < 3){
    
    }
  }
  //reset motorID for next loop through;
}


