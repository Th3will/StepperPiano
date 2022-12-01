const int stepPin[3] = {9,11,13}; 
const int dirPin[3] = {8,10,12}; 

// here comes a bunch of 'useful' vars; dont mind
int coun;
bool dir=0;
int del;

int use=180;
int tempo=120;
int oct=5;
//int notes[8] = {1912, 1703, 1517, 1431, 1275, 1136, 1012, 956};
const int notes[8] = {956, 851, 758, 715, 637, 568, 506, 478};
int motDel[3] = {0,0,0};
//bool motState[3] = {false,false,false};

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

  digitalWrite(dirPin[0],dir);
  digitalWrite(dirPin[1],dir);
  digitalWrite(dirPin[2],dir);


}
void loop() {
  int motorId = 0;
  for (int i = 0; i < 8; i++)
  {
    if(digitalRead(i) == LOW && motorId < 3){
      note(notes[i],10,motorId);
      //motDel[motorId] = notes[i];
      motorId++;
    }
    //play();
  }
  
 

}

void note(int num,long dur,int motor) {
  /* coun=floor((dur*5*tempo)/num);
  for(int x = 0; x < coun; x++) { */
    digitalWrite(stepPin[motor],HIGH);
    delayMicroseconds(num);
    digitalWrite(stepPin[motor],LOW);
    delayMicroseconds(num);
  //}
}
void play(){
  for (int i = 0; i < 3; i++)
  {
    
  }
  
}

   int note(int num){
    del = (num*oct)/10;
    return del;
  } 


