#include <Arduino.h>
//#include <cmath>
//#include "A4988.h "
#include "Motor.h"


/*TODO
  Implement a motor playing solution that works
  Make Motor Scheduler w/ cases
  Make everything into a struct and cleanup
*/

//Shift Register pins
const int load = 7;
const int clockIn = 6;
const int dataIn = 5;
const int clockEnablePin = 4;

//Shift Register Input
byte incoming;

// here comes a bunch of 'useful' vars; dont mind
int coun;
int oct = 5;
int note;
bool dir=0;
const int use=180;
const int tempo=120;

const int notes[8] = {1012, 1136, 1275, 1431, 1517, 1703, 1912, 2024};
//Motor pins; Left->Mid->Right
const int motorStep[3] = {8,10,12};
const int motorDir[3] = {9,11,13};
//cycles through during loop to schedule which motor
int motorID;


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
    pinMode(1,INPUT_PULLUP);
    pinMode(2,INPUT_PULLUP);
    pinMode(3,INPUT_PULLUP);
    pinMode(4,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
    pinMode(6,INPUT_PULLUP);
    pinMode(7,INPUT_PULLUP);

}

//play music
void note(int num, int motorID) {
  del=(num*oct)/10;
  digitalWrite(motorDir[motorID],dir);
  //x in x*5*temp is duration in milliseconds
  coun=floor((1*5*tempo)/del);
  for(int x = 0; x < coun; x++) {
    digitalWrite(motorStep[motorID],HIGH);
    delayMicroseconds(del);
    digitalWrite(motorStep[motorID],LOW);
    delayMicroseconds(del);
  }
  motorID++;
  Serial.println("detected note nextMotor");
}

void setup() {
    motorInit();
    keyInit();
    Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < 8; i++)
  {
    //check button pressed and hasn't already scheduled all other avai
    if(digitalRead(i)&&motorID < 4){
      note(notes[i],motorID);
    }
  }
  //reset motorID for next loop through;
 motorID = 0;
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


