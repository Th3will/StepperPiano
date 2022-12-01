const int stepPin[3] = {9,11,13}; 
const int dirPin[3] = {8,10,12}; 

// here comes a bunch of 'useful' vars; dont mind
int coun;
bool dir=0;
int del;

int use=180;
int tempo=120;
int oct=5;
const int notes[8] = {1912, 1703, 1517, 1431, 1275, 1136, 1012, 956};

void setup() {
  // Sets the two pins as Outputs
  Serial.begin(9600);

  pinMode(stepPin[0],OUTPUT); 
  pinMode(dirPin[0],OUTPUT);
  
  pinMode(stepPin[1],OUTPUT); 
  pinMode(dirPin[1],OUTPUT);
  
  pinMode(stepPin[2],OUTPUT); 
  pinMode(dirPin[2],OUTPUT);

  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);

}
void loop() {
  int motorId = 0;
  oct=5;
  for (int i = 0; i < 8; i++)
  {
    /* code */
    if(digitalRead(i) == LOW && motorId < 3){
      note(notes[i],35,motorId);
      motorId++;
    }
  }
  
 

}

void note(int num,long dur,int motor) {
  del=(num*oct)/10;
  //dir=!dir;
 digitalWrite(dirPin[motor],dir);
  coun=floor((dur*5*tempo)/del);
  for(int x = 0; x < coun; x++) {
    digitalWrite(stepPin[motor],HIGH);
    delayMicroseconds(del);
    digitalWrite(stepPin[motor],LOW);
    delayMicroseconds(del);
  }

}

