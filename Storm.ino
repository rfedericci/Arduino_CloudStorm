//Select the pin you want to use for the lightings. Here I took 8 ouputs, some are digitals (2/4/7/8/12) the other analogs (3/5/9). 
//I use the digital pin 13 as input to control weither or not the cloud is in mode Storm. If the pin 13 read 0, all the clusters are ON, if not the clusters blink to simulate lightings.


int Cluster1 = 2;
int Cluster2 = 3;
int Cluster3 = 4;
int Cluster4 = 5;
int Cluster5 = 7;
int Cluster6 = 8;
int Cluster7 = 9;
int Cluster8 = 12;
int ReadBool = 13;



int rand1;
int rand2;
int rand3;
int rand4;
int rand5;
int rand6;
int rand7;
int rand8;

int Tshort1;
int Tshort2;
int Tshort3;
int Tshort4;
int Tshort5;
int Tshort6;
int Tlong1;
int Tlong2;

int Mode = 0;
int Modenm1 = 0;
int State = 1;

long TimeStart = long(millis()/1000);


void setup() {
Serial.begin(9600);
pinMode(Cluster1, OUTPUT);
pinMode(Cluster2, OUTPUT);
pinMode(Cluster3, OUTPUT);
pinMode(Cluster4, OUTPUT);
pinMode(Cluster5, OUTPUT);
pinMode(Cluster6, OUTPUT);
pinMode(Cluster7, OUTPUT);
pinMode(Cluster8, OUTPUT);
pinMode(ReadBool, INPUT);
}

void normale(){
digitalWrite(Cluster1, true);
analogWrite(Cluster2, 255);
digitalWrite(Cluster3, true);
analogWrite(Cluster4, 255);
digitalWrite(Cluster5, true);
digitalWrite(Cluster6, true);
analogWrite(Cluster7, 255);
digitalWrite(Cluster8, true);
}

void RandInt(){
rand1 = bool(random(0, 2));
rand2 = int(bool(random(0, 2)))*255;
rand3 = bool(random(0, 2));
rand4 = int(bool(random(0, 2)))*255;
rand5 = bool(random(0, 2));
rand6 = bool(random(0, 2));
rand7 = int(bool(random(0, 2)))*255;
rand8 = bool(random(0, 2));
}

void RandDelay(){
Tshort1 = random(0, 100);
Tshort2 = random(0, 100);
Tshort3 = random(0, 100);
Tshort4 = random(0, 100);
Tshort5 = random(0, 100);
Tshort6 = random(0, 100);
Tlong1 = random(0, 500);
Tlong2 = random(1000, 2000);
}

void Lighting(int DelayON_start, int DelayON_end, int DelayOFF_start, int DelayOFF_end)
{
RandInt();
TurnOn();
delay(random(DelayON_start, DelayON_end));
TurnOff();
delay(random(DelayOFF_start, DelayOFF_end));
}

void TurnOn(){
digitalWrite(Cluster1, rand1);
analogWrite(Cluster2, rand2);
digitalWrite(Cluster3, rand3);
analogWrite(Cluster4, rand4);
digitalWrite(Cluster5, rand5);
digitalWrite(Cluster6, rand6);
analogWrite(Cluster7, rand7);
digitalWrite(Cluster8, rand8);
}

void TurnOff(){
digitalWrite(Cluster1, LOW);
analogWrite(Cluster2, LOW);
digitalWrite(Cluster3, LOW);
analogWrite(Cluster4, LOW);
digitalWrite(Cluster5, LOW);
digitalWrite(Cluster6, LOW);
analogWrite(Cluster7, LOW);
digitalWrite(Cluster8, LOW);
}

void storm(){
int NbLightings = random(0, 9);
  for (int n=0; n<NbLightings; n++)
  {
  Lighting(30, 80, 30, 80); 
  }
  Lighting(50, 100, 1000, 4000);
}

void loop() {
  Serial.println(long(millis()/1000) - TimeStart);

  Mode = digitalRead(ReadBool);  
  if (long(millis()/1000) - TimeStart > 10)
  {
    State = 0;
    Serial.println(1);
    TurnOff();
  }
  if (Modenm1 != Mode)
  {
    State = 1;
    TimeStart = long(millis()/1000);
    Serial.println(12);
  }
  Modenm1 = Mode;
  
  if (Mode == 0 && State == 1) {    
    storm();
    Serial.println(3);
  }
  if (Mode == 1 && State == 1) {
    normale();
    Serial.println(4);
  }
  delay(1000);
}
    
