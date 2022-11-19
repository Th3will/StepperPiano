//Notes.cpp
#include <Arduino.h>
class Motor{
    private:
        //Device info
        // using a 200-step motor (most common)
        const int motorSteps = 200;

        //driver
        int stepPin; 
        int dirPin;
        bool inUse = false;
        bool dir;
        int del;
        bool isPressed;
        int oct = 5;
    public:
        Motor(int step, int dir);
        void init();
        void note(int num);
        bool getInUse() const;
};

Motor::Motor(int step, int dir){
  stepPin = step;
  dirPin = dir;
}; 

void Motor::init(){
            // Sets the two pins as Outputs
            pinMode(stepPin,OUTPUT); 
            pinMode(dirPin,OUTPUT);
      }

//take in note, calculate valid rotation speed, check which motor is free
void Motor::note(int num) {
  inUse = true;
  //calculate delay
  del=(num*oct)/10;
  //change direction to ensure lack of conflict
  dir=!dir;
 digitalWrite(dirPin,dir);
  //count=floor((dur*5*tempo)/del);
  while(isPressed){
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(del);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(del);
  }
}

  bool Motor::getInUse() const{
    return inUse;
  }

