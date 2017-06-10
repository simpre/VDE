#include <CmdMessenger.h>  // CmdMessenger


volatile  int     cnt = 0;
volatile  int     dist = 0;
volatile  boolean dir = false;

// Motor 1 
const     int   M0_pin = 9;
const     int   M1_pin = 10;
const     int   interrupt_pin = 2;
const     int   tach_pin = 4;
const     int   enabledriver = 3;

////Motor 2
//
unsigned long systime = 0 ;
unsigned long old_systime =0 ;

long  testtime  = 0;
long  testdist = 0;
long  testspeed = 255;
int   durchlauf = 0;

// Attach a new CmdMessenger object to the default Serial port
CmdMessenger cmdMessenger = CmdMessenger(Serial);

// This is the list of recognized commands. These can be commands that can either be sent or received. 
// In order to receive, attach a callback function to these events
enum
{ 
  kturn ,
  kstopp ,
  kStatus ,
};

// Callbacks define on which received commands we take action
void attachCommandCallbacks(){
  // Attach callback methods
  cmdMessenger.attach(OnUnknownCommand);
  cmdMessenger.attach(kstopp, stopp );
  cmdMessenger.attach(kturn, turnforward);

}
// Called when a received command has no attached function
void OnUnknownCommand(){
  cmdMessenger.sendCmd(kStatus,"Command without attached callback");
}
void setup() {
  //Setup für Messenger
  Serial.begin(115200);  
  cmdMessenger.printLfCr();  // Adds newline to every command 
  attachCommandCallbacks();  // Attach my application's user-defined callback methods
  // Send the status to the PC that says the Arduino has booted
  // Note that this is a good debug function: it will let you also know 
  // if your program had a bug and the arduino restarted  
  cmdMessenger.sendCmd(kStatus,"Arduino has started!");

  //Setup für Motor
  attachInterrupt(digitalPinToInterrupt(2),count,RISING);
  old_systime= millis();
  pinMode(M0_pin,OUTPUT);
  pinMode(M1_pin,OUTPUT); 
  pinMode (enabledriver,OUTPUT);  
  pinMode(13,OUTPUT);
  digitalWrite (enabledriver,HIGH);
  delay(500);
 

}
void loop() {

// Process incoming serial data, and perform callbacks
  cmdMessenger.feedinSerialData();
    
}
long updatespeed(){
  long  i = (cnt*360) / (millis() -  old_systime );
  cnt = 0;
  old_systime = millis();
  if (dir)
  {
    i = i*-1;
    }
  return i; 
  }
void count (){
 dir = digitalRead(tach_pin);
 cnt++; 
 dist++;
  }
void turnforward (int speeed){
  digitalWrite (enabledriver,HIGH);
  analogWrite (M0_pin,speeed);
  analogWrite (M1_pin,0);
  } 
void turnbackward (int speeed){
  digitalWrite (enabledriver,HIGH);
  analogWrite (M1_pin,speeed);
  analogWrite (M0_pin,0);
  } 
void stopp(){  
  digitalWrite (13,LOW);
  digitalWrite(M1_pin,LOW);
  digitalWrite(M0_pin,LOW);
  digitalWrite(enabledriver,LOW);
}
void turnfor(boolean dir, int speeed , int rotations){
long   begin_dist = dist;
long   differenz = (rotations*180)-(speeed/5);
if(dir)
{
  turnforward(speeed);
}
else
{
  turnbackward(speeed);  
} 
while (dist<begin_dist+differenz)
{
  delayMicroseconds(10);  
}
stopp();
}
void turnforward(){
  digitalWrite(13,HIGH); 
  turnforward(128);
  }
