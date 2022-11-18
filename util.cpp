#include <arduino.h>
#include "player.h"



class inpProc{
    private:
        byte incoming;
        bool switches[8] = {false,false,false,false,false,false,false,false};
        int place;
        int load; 
        int clockIn;
        int clockEnablePin;
        int dataIn;
    public: 
        void GetData();
        void ByteFlips(int num);
        bool CheckOnePress();
        void FlipAndPrintArray();
};

//GET RID OF



void inpProc::GetData(){
  digitalWrite(load, LOW);
  delayMicroseconds(5);
  digitalWrite(load, HIGH);
  delayMicroseconds(5);

  // Get data from 74HC165
  digitalWrite(clockIn, HIGH);
  digitalWrite(clockEnablePin, LOW);
  incoming = shiftIn(dataIn, clockIn, LSBFIRST);
  place = incoming/1;
  /* digitalWrite(clockEnablePin, HIGH);
  Serial.print("Pin States:\r\n");
  Serial.println(incoming, BIN);
  delay(200); */
}

// changes switches to correspond to buttons pressed
void inpProc::ByteFlips(int num){
  int count = 0;
  int placeholder = num/1;
  //Serial.println(placeholder);
  for (int i = 128; i >= 1; i/=2){
    if((placeholder/i) == 1){
      switches[count] = true;
      placeholder -= i;
      //Serial.println(count);
      //Serial.println(placeholder);
    }else{
      switches[count] = false;
    }
      count++;
  }  
    FlipAndPrintArray();
}

bool inpProc::CheckOnePress(){
  for (int i = 0; i < 8; i++){
    if (switches[i] == true){
      for (int j = i+1; j < 8; j++){
        if (switches[j] ==true){
          return false;
        }
      }
    }
  }
  return true;
}

void inpProc::FlipAndPrintArray(){
  for(int i = 1; i < 4; i++){
    if(switches[i] == 1){
      switches[i] = 0;
    }
    else{
      switches[i] = 1;
    }
  }
  for(int i = 0; i < 8; i++){
    Serial.print(switches[i]);
  }
  Serial.println();
}