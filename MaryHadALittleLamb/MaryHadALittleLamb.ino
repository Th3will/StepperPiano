const int stepPin = 9; 
const int dirPin = 8; 

// here comes a bunch of 'useful' vars; dont mind
int coun;
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

void setup() {
  // Sets the two pins as Outputs
  Serial.begin(9600);

  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
  
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
  oct=5;
  int sensorVal0 = digitalRead(0);
  int sensorVal1 = digitalRead(1);
  int sensorVal2 = digitalRead(2);
  int sensorVal3 = digitalRead(3);
  int sensorVal4 = digitalRead(4);
  int sensorVal5 = digitalRead(5);
  int sensorVal6 = digitalRead(6);
  int sensorVal7 = digitalRead(7);

// Here you put your music code

  if(sensorVal0 == LOW) note(c,35);
  if(sensorVal1 == LOW) note(d,35);
  if(sensorVal2 == LOW) note(e,35);
  if(sensorVal3 == LOW) note(f,35);
  if(sensorVal4 == LOW) note(g,35);
  if(sensorVal5 == LOW) note(a,35);
  if(sensorVal6 == LOW) note(b,35);
  if(sensorVal7 == LOW) note(c/2,35);

}

void note(int num,long dur) {
  del=(num*oct)/10;
  //dir=!dir;
 digitalWrite(dirPin,dir);
  coun=floor((dur*5*tempo)/del);
  for(int x = 0; x < coun; x++) {
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