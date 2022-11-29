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
        int count;
        const int notes[8] = {2024,1912,1703,1517,1431,1275,1136,1012};

    public:
        Motor(int step, int dir);
        void init();
        void play(int note);
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
void Motor::play(int note) {
  if (note != -1){
    del=(notes[note]*oct)/10;
    dir = !dir;
    digitalWrite(dirPin, dir);
    count=floor((1*5*120)/del);
    for(int x = 0; x < count; x++) {
      digitalWrite(stepPin,HIGH);
      delayMicroseconds(del);
      digitalWrite(stepPin,LOW);
      delayMicroseconds(del);
    }
  }
    
  }

  bool Motor::getInUse() const{
    return inUse;
  }

