//Notes.cpp
#include <Arduino.h>
class Player{
    private:
        //key values
        

        int oct = 5;
        int del;
        bool dir=0;
        const int use=180;
        const int tempo=120;
        int count;



        //Device info
        // using a 200-step motor (most common)
        const int motorSteps = 200;
        //driver
        const int stepPin = 9; 
        const int dirPin = 8; 
        const int MS1 = 10;
        const int MS2 = 11;
        const int MS3 = 12;
        //serialout
        const int load = 7;
        const int clockIn = 6;
        const int dataIn = 5;
        const int clockEnablePin = 4;


        //index corresponds to which motor to send input to
        int scheduler[3] = {0,0,0};

    public:
        Player();
        void devInit();
        void refreshScheduler(int* newSched);
        int getNote(int note){
            return note;
        }
        void note(int num, long dur);
        
};

Player::Player(){
}; //keep all values

void Player::devInit(){
            Serial.begin(9600);
            // Sets the two pins as Outputs
            pinMode(stepPin,OUTPUT); 
            pinMode(dirPin,OUTPUT);
            pinMode(load, OUTPUT);
            pinMode(clockEnablePin, OUTPUT);
            pinMode(clockIn, OUTPUT);
            pinMode(dataIn, INPUT);
        }

void Player::refreshScheduler(int* newSched){
    if(sizeof(newSched) != 3){

    } else {
      for (size_t i = 0; i < 3; i++)
      {
        scheduler[i] = newSched[i];
      }
          }
}

void Player::note(int num,long dur) {
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
