//Define Motor Port Konstanten
//Port A
#define A_M1  4       //pin Motor 1
#define A_M2  24      //pin Motor 2
#define A_EN1 2       //pin Encorde 1  && interrupt
#define A_EN2 31      //pin Encoder 2
#define A_Enable 5    //pin Enable driver
//Port B
#define B_M1  6
#define B_M2  28
#define B_EN1 3
#define B_EN2 32
#define B_Enable 27
//Port C
#define C_M1  8
#define C_M2  7
#define C_EN1 18
#define C_EN2 33
#define C_Enable 9
//Port D
#define D_M1  10
#define D_M2  30
#define D_EN1 17
#define D_EN2 34
#define D_Enable 29
//Port 1
struct SensorPort {
  byte analogPin;
  byte digitalPin1;
  byte digitalPin2;
}; 
const SensorPort SensorPort1 = {A8,35,36};
const SensorPort SensorPort2 = {A9,37,38};
const SensorPort SensorPort3 = {A10,41,42};
const SensorPort SensorPort4 = {A11,39,40};


void Motor_Begin(){
  MotorA_Begin();
  MotorB_Begin();
  MotorC_Begin();
  MotorD_Begin();
  }

// Motor A Methoden
boolean           MotorA_dir  ;
volatile int      MotorA_count = 0;
volatile long     MotorA_dist = 0;
boolean           MotorA_hardStopp = true;
long              MotorA_lastTimeMesaured;
long              MotorA_timeBetweenInterrupt;
void              MotorA_Begin(){
  pinMode(A_M1,OUTPUT);
  pinMode(A_M2,OUTPUT);
  pinMode(A_Enable,OUTPUT);
  pinMode(A_EN1,INPUT);
  pinMode(A_EN2,INPUT);
  MotorA_lastTimeMesaured = millis();
  attachInterrupt(digitalPinToInterrupt(A_EN1), MotorA_isr, RISING);
  
  }
void              MotorA_isr(){
  MotorA_dir = digitalRead(A_EN2);
  MotorA_count++;
  MotorA_dist++;
  MotorA_timeBetweenInterrupt = micros() - MotorA_lastTimeMesaured;
  MotorA_lastTimeMesaured = micros();
  delay(2);
  }
void              MotorA_setHardStopp(boolean pEnable){
  MotorA_hardStopp = pEnable;
  }
void              MotorA_enableDriver(){
   digitalWrite(5,HIGH);
  }
void              MotorA_disableDriver(){
  digitalWrite(A_Enable,LOW);
  }
void              MotorA_forward(byte pSpeed){
 MotorA_enableDriver();
 analogWrite(A_M1,pSpeed);
 digitalWrite(A_M2,LOW);
  }
void              MotorA_backward(byte pSpeed){
  MotorA_enableDriver();
  pSpeed = (pSpeed*(-1))+255;
  analogWrite(A_M1,pSpeed);
  digitalWrite(A_M2,HIGH);
  }
void              MotorA_stopp(){
  digitalWrite(A_M1,LOW);
  digitalWrite(A_M2,LOW);
  if(!MotorA_hardStopp){
  digitalWrite(A_Enable,LOW);  
  } 
  }
long              MotorA_getSpeed(){
  long a = 1000000/MotorA_timeBetweenInterrupt;
  if(a<50){ return 0;}
  return 1000000/MotorA_timeBetweenInterrupt;
  }
boolean           MotorA_getDirection(){          //true if forward
  return MotorA_dir;
  }
long              MotorA_getDistance(){
  return MotorA_dist;
  }
void              MotorA_setDistanceToNull(){
  MotorA_dist = 0;
  }
// Motor B Methoden
boolean           MotorB_dir  ;
volatile int      MotorB_count = 0;
volatile long     MotorB_dist = 0;
boolean           MotorB_hardStopp = true;
long              MotorB_lastTimeMesaured;
long              MotorB_timeBetweenInterrupt;
void              MotorB_Begin(){
  pinMode(B_M1,OUTPUT);
  pinMode(B_M2,OUTPUT);
  pinMode(B_Enable,OUTPUT);
  pinMode(B_EN1,INPUT);
  pinMode(B_EN2,INPUT);
  MotorB_lastTimeMesaured = millis();
  attachInterrupt(digitalPinToInterrupt(B_EN1), MotorB_isr, RISING);
  
  }
void              MotorB_isr(){
  MotorB_dir = digitalRead(B_EN2);
  MotorB_count++;
  MotorB_dist++;
  MotorB_timeBetweenInterrupt = micros() - MotorB_lastTimeMesaured;
  MotorB_lastTimeMesaured = micros();
  delay(2);
  }
void              MotorB_setHardStopp(boolean pEnable){
  MotorB_hardStopp = pEnable;
  }
void              MotorB_enableDriver(){
   digitalWrite(5,HIGH);
  }
void              MotorB_disableDriver(){
  digitalWrite(B_Enable,LOW);
  }
void              MotorB_forward(byte pSpeed){
 MotorB_enableDriver();
 analogWrite(B_M1,pSpeed);
 digitalWrite(B_M2,LOW);
  }
void              MotorB_backward(byte pSpeed){
  MotorB_enableDriver();
  pSpeed = (pSpeed*(-1))+255;
  analogWrite(B_M1,pSpeed);
  digitalWrite(B_M2,HIGH);
  }
void              MotorB_stopp(){
  digitalWrite(B_M1,LOW);
  digitalWrite(B_M2,LOW);
  if(!MotorB_hardStopp){
  digitalWrite(B_Enable,LOW);  
  } 
  }
long              MotorB_getSpeed(){
  long a = 1000000/MotorB_timeBetweenInterrupt;
  if(a<50){ return 0;}
  return 1000000/MotorB_timeBetweenInterrupt;
  }
boolean           MotorB_getDirection(){          //true if forward
  return MotorB_dir;
  }
long              MotorB_getDistance(){
  return MotorB_dist;
  }
void              MotorB_setDistanceToNull(){
  MotorB_dist = 0;
  }
                  // Motor C Methoden
boolean           MotorC_dir  ;
volatile int      MotorC_count = 0;
volatile long     MotorC_dist = 0;
boolean           MotorC_hardStopp = true;
long              MotorC_lastTimeMesaured;
long              MotorC_timeBetweenInterrupt;
void              MotorC_Begin(){
  pinMode(C_M1,OUTPUT);
  pinMode(C_M2,OUTPUT);
  pinMode(C_Enable,OUTPUT);
  pinMode(C_EN1,INPUT);
  pinMode(C_EN2,INPUT);
  MotorC_lastTimeMesaured = millis();
  attachInterrupt(digitalPinToInterrupt(C_EN1), MotorC_isr, RISING);
  
  }
void              MotorC_isr(){
  MotorC_dir = digitalRead(C_EN2);
  MotorC_count++;
  MotorC_dist++;
  MotorC_timeBetweenInterrupt = micros() - MotorC_lastTimeMesaured;
  MotorC_lastTimeMesaured = micros();
  delay(2);
  }
void              MotorC_setHardStopp(boolean pEnable){
  MotorC_hardStopp = pEnable;
  }
void              MotorC_enableDriver(){
   digitalWrite(5,HIGH);
  }
void              MotorC_disableDriver(){
  digitalWrite(C_Enable,LOW);
  }
void              MotorC_forward(byte pSpeed){
 MotorC_enableDriver();
 analogWrite(C_M1,pSpeed);
 digitalWrite(C_M2,LOW);
  }
void              MotorC_backward(byte pSpeed){
  MotorC_enableDriver();
  pSpeed = (pSpeed*(-1))+255;
  analogWrite(C_M1,pSpeed);
  digitalWrite(C_M2,HIGH);
  }
void              MotorC_stopp(){
  digitalWrite(C_M1,LOW);
  digitalWrite(C_M2,LOW);
  if(!MotorC_hardStopp){
  digitalWrite(C_Enable,LOW);  
  } 
  }
long              MotorC_getSpeed(){
  long a = 1000000/MotorC_timeBetweenInterrupt;
  if(a<50){ return 0;}
  return 1000000/MotorC_timeBetweenInterrupt;
  }
boolean           MotorC_getDirection(){          //true if forward
  return MotorC_dir;
  }
long              MotorC_getDistance(){
  return MotorC_dist;
  }
void              MotorC_setDistanceToNull(){
  MotorC_dist = 0;
  }

                  // Motor D Methoden
boolean           MotorD_dir  ;
volatile int      MotorD_count = 0;
volatile long     MotorD_dist = 0;
boolean           MotorD_hardStopp = true;
long              MotorD_lastTimeMesaured;
long              MotorD_timeBetweenInterrupt;
void              MotorD_Begin(){
  pinMode(D_M1,OUTPUT);
  pinMode(D_M2,OUTPUT);
  pinMode(D_Enable,OUTPUT);
  pinMode(D_EN1,INPUT);
  pinMode(D_EN2,INPUT);
  MotorD_lastTimeMesaured = millis();
  attachInterrupt(digitalPinToInterrupt(D_EN1), MotorD_isr, RISING);
  
  }
void              MotorD_isr(){
  MotorD_dir = digitalRead(D_EN2);
  MotorD_count++;
  MotorD_dist++;
  MotorD_timeBetweenInterrupt = micros() - MotorD_lastTimeMesaured;
  MotorD_lastTimeMesaured = micros();
  delay(2);
  }
void              MotorD_setHardStopp(boolean pEnable){
  MotorD_hardStopp = pEnable;
  }
void              MotorD_enableDriver(){
   digitalWrite(5,HIGH);
  }
void              MotorD_disableDriver(){
  digitalWrite(D_Enable,LOW);
  }
void              MotorD_forward(byte pSpeed){
 MotorD_enableDriver();
 analogWrite(D_M1,pSpeed);
 digitalWrite(D_M2,LOW);
  }
void              MotorD_backward(byte pSpeed){
  MotorD_enableDriver();
  pSpeed = (pSpeed*(-1))+255;
  analogWrite(D_M1,pSpeed);
  digitalWrite(D_M2,HIGH);
  }
void              MotorD_stopp(){
  digitalWrite(D_M1,LOW);
  digitalWrite(D_M2,LOW);
  if(!MotorD_hardStopp){
  digitalWrite(D_Enable,LOW);  
  } 
  }
long              MotorD_getSpeed(){
  long a = 1000000/MotorD_timeBetweenInterrupt;
  if(a<50){ return 0;}
  return 1000000/MotorD_timeBetweenInterrupt;
  }
boolean           MotorD_getDirection(){          //true if forward
  return MotorD_dir;
  }
long              MotorD_getDistance(){
  return MotorD_dist;
  }
void              MotorD_setDistanceToNull(){
  MotorD_dist = 0;
  }

class SoundSensor{
  private:
  SensorPort        PortOfThis;
  int inMinimum     = 10;
  int inMaximum     = 210;
  int outMinimum    = 0;
  int outMaximum    = 255 ;
  int SensorValue   ;
  public:
  SoundSensor(SensorPort a ){
    PortOfThis = a;
    pinMode (PortOfThis.analogPin,INPUT);
    }
  int   readRaw(){
    return analogRead(PortOfThis.analogPin);
    }
  int   read(){
    return map(readRaw(),inMinimum,inMaximum,outMinimum,outMaximum);
    }
  void  setInMaximum (int n){
    inMaximum = n;
    } 
  void  setInMinimum(int n){
    inMaximum = n;
  }
  void  setOutMaximum(int n){
    outMaximum = n;
    }
  void  setOutMinimum(int n){
    outMinimum = n;
    }
  };
class LightSensor{
  private:
  SensorPort        PortOfThis;
  int inMinimum     = 0;
  int inMaximum     = 750;
  int outMinimum    = 0;
  int outMaximum    = 255 ;
  int SensorValue   ;
  public:
  LightSensor(SensorPort a ){
    PortOfThis = a;
    pinMode (a.analogPin,INPUT);
    pinMode (a.digitalPin1,OUTPUT);
    }
  int   readRaw(){
    return analogRead(A8);
    }
  int   read(){
    return   map(readRaw(),inMinimum,inMaximum,outMinimum,outMaximum);

    }
  void  setInMaximum (int n){
    inMaximum = n;
    } 
  void  setInMinimum(int n){
    inMaximum = n;
  }
  void  setOutMaximum(int n){
    outMaximum = n;
    }
  void  setOutMinimum(int n){
  };
  void  setLedStat(boolean pState){
    digitalWrite(PortOfThis.digitalPin1,pState);
    }
};
LightSensor Lausch(SensorPort1);

void setup() {

  Serial.begin(1000000);
  delayMicroseconds(500);
  //Lausch.LedStat(HIGH);
  Lausch.setLedStat(HIGH);
  }

void loop() {
//  int a = Lausch.readRaw();

Serial.println(Lausch.readRaw());

//Serial.println(analogRead(A8));
delay(100);

}
