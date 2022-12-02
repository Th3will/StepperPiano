//TIMEDACTION

class TimedAction {
  
  public:
    TimedAction(unsigned long interval,void (*function)());
    TimedAction(unsigned long prev,unsigned long interval,void (*function)());
	
	void reset();
	void disable();
	void enable();
	void check();
	
	void setInterval( unsigned long interval );

  private: 
    bool active;
    unsigned long previous;
    unsigned long interval;
    void (*execute)();
		
};

const int stepPin[3] = {9,11,13}; 
const int dirPin[3] = {8,10,12};

void play0();
void play1();
void play2();

TimedAction mot0 = TimedAction(100, play0);
TimedAction mot1 = TimedAction(100, play1);
TimedAction mot2 = TimedAction(100, play2);


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
bool motState[3] = {false,false,false};

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
  int time = millis(); 
  int motorId = 0;
  for (int i = 0; i < 8; i++)
  {
    if(digitalRead(i) == LOW && motorId < 3){
      switch (motorId)
      {
      case 0:
        mot0.setInterval(notes[i]);
        motorId++;
        break;
      case 1:
        mot1.setInterval(notes[i]);
        motorId++;
        break;
      case 2:
        mot2.setInterval(notes[i]);
        motorId++;
        break;
      default:
        break;
      }
    }   
    mot0.check();
    mot1.check();
    mot2.check();
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
void play0(){
  digitalWrite(stepPin[0],motState[0]);
  motState[0] = !motState[0];
}

void play1(){
  digitalWrite(stepPin[1],motState[1]);
  motState[1] = !motState[1];
}

void play2(){
  digitalWrite(stepPin[2],motState[2]);
  motState[2] = !motState[2];
}
   int note(int num){
    del = (num*oct)/10;
    return del;
  } 

/*
|| <<constructor>>
*/
TimedAction::TimedAction(unsigned long intervl,void (*function)()){
    active = true;
	previous = 0;
	interval = intervl;
	execute = function;
}

/*
|| <<constructor>>
*/
TimedAction::TimedAction(unsigned long prev,unsigned long intervl,void (*function)()){
    active = true;
	previous = prev;
	interval = intervl;
	execute = function;
}

void TimedAction::reset(){
    previous = millis();
}

void TimedAction::disable(){
    active = false;
}

void TimedAction::enable(){
	active = true;
}

void TimedAction::check(){
  if ( active && (millis()-previous >= interval) ) {
    previous = millis();
    execute();
  }
}

void TimedAction::setInterval( unsigned long intervl){
	interval = intervl;
}
