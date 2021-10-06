
int ECHO=11;
int TRIG=10;
float a,b,A;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  Serial.begin(9600);
  a=getDistance();
  b=a;
  }

float getDistance(){
  float time;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(10);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
    
  time=pulseIn(ECHO,HIGH);

  return time*170*0.000001;
}

bool check1(){
  bool c=true;
  for(int i=0;i<5;i++){
    if(getDistance()>2){c=false;break;}
    delay(100);
    }
   return c;
  }

 bool check2(){
  bool c=true;
  for(int i=0;i<5;i++){
    if(getDistance()<2){c=false;break;}
    delay(100);
    }
   return c;
  }
  



void loop() {
  while(true){
    if(check1()){break;}
    delay(100);
    }
  
    Serial.println(1,DEC);

    digitalWrite(12,HIGH);
    delay(500);
    digitalWrite(12,LOW);

   while(true){
      if(check2()){break;}
      delay(100);
      }
   Serial.println(0,DEC);
                
   delay(100);

    }
