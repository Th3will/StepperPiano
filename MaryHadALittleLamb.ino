#include <Arduino.h>
#include "A4988.h"
#include "Notes.h"


/*TODO
  Implement a motor playing solution that works
  Make Motor Scheduler w/ cases
  Make everything into a struct and cleanup
*/


// using a 200-step motor (most common)
#define MOTOR_STEPS 200
// configure the pins connected
#define DIR 8
#define STEP 9
#define MS1 10
#define MS2 11
#define MS3 12
#define SLPRST 13
// defines pins numbers
const int stepPin = 9; 
const int dirPin = 8; 
const int load = 7;
int clockIn = 6;
int dataIn = 5;
const int clockEnablePin = 4;


// here comes a bunch of 'useful' vars; dont mind
int count;
bool dir=0;
int del;
int c=1912;
int cf=1805;
int d= 1703;
int df=1607;
int e=1517;
int f=1431;
int ff=1351;
int g= 1275;
int gf=1203;
int a=1136;
int af=1072;
int b=1012;
int c1=floor(c/2);
int cf1=floor(cf/2);
int d1=floor(d/2);
int df1=floor(df/2);
int e1=floor(e/2);
int f1=floor(1431/2);
int ff1=floor(1351/2);
int g1= floor(1275/2);
int gf1=floor(1203/2);
int a1=floor(1136/2);
int af1=floor(1072/2);
int b1=floor(1012/2);
int e0=e*2;
int g0=g*2;
int b0=b*2;
int af0=af*2;
int a0=a*2;
int f0=f*2;
int use=180;
int tempo=120;
int oct=5;

int first[] = {e,d,c,d,e,e,e};
int second[] = {d,d,d,e,g,g};
int fourth[] = {e,d,d,e,d,c};

int place;

void setup() {
  Serial.begin(9600);
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  pinMode(load, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockIn, OUTPUT);
  pinMode(dataIn, INPUT);
}
void loop() {
  oct=5;
// Here you put your music code
  /* note(c,1000);
  pa(250);
  note(d,1000);
  pa(250);
  note(e,1000);
  pa(250);
  note(f,1000);
  pa(250);
  note(g,1000);
  pa(250);
  note(a,1000);
  pa(250);
  note(b,1000);
  pa(250); */
  //littleLamb();
  //getData();
  getData();
  byteFlips(place);
  play();
}

void littleLamb(){
  for (int i = 0; i < 7; i++){
    note(first[i],500);
    pa(200);
  }
  for (int i = 0; i < 6; i++){
    note(second[i],500);
    pa(200);
  }
  for (int i = 0; i < 7; i++){
    note(first[i],500);
    pa(200);
  }
  for (int i = 0; i < 6; i++){
    note(fourth[i],500);
    pa(200);
  }
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

byte incoming;
void getData(){
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
bool switches[8] = {false,false,false,false,false,false,false,false};

// changes switches to correspond to buttons pressed
void byteFlips(int num){
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
  flipAndPrintArray();
}

//checks that only one note is pressed
bool checkOnePress(){
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
//check that only one note is pressed and play corresponding key
void play(){
    for (int i = 0; i < 8; i++){
    if (switches[i] == 1){
      switch (i) {
        case 1:
          note(c,100);
          break;
        case 2:
          note(d,100);
          break;
        case 3:
          note(e,100);
          break;
        default:
          pa(100);
          break;
      }
    }
}
}

void flipAndPrintArray(){
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

void testByteFlips(){
  int num1 = 123;
  int num2 = 0;
  int num3 = 255;
  int num4 = 126;

  byteFlips(num1);
  Serial.print("num1 = " );
  Serial.println(switchesToInt());

  byteFlips(num2);
  Serial.print("num2 = " );
  Serial.println(switchesToInt());

  
  byteFlips(num3);
  Serial.print("num3 = " );
  Serial.println(switchesToInt());

  
  byteFlips(num4);
  Serial.print("num4 = " );
  Serial.println(switchesToInt());
}
*/

