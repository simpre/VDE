#include <CmdMessenger.h>  // CmdMessenger
// Attach a new CmdMessenger object to the default Serial port
CmdMessenger cmdMessenger = CmdMessenger(Serial);
enum
{
  kSetOn,
  kSetOff,  
};

bool state = false;
void attachCommandCallbacks(){
  cmdMessenger.attach(kSetOn,kOn);
  cmdMessenger.attach(kSetOff,kOff);
  }
void kOn()
{
   digitalWrite(13,HIGH);
  }
void kOff(){
  digitalWrite(13,LOW);  
}

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(5,INPUT); 
  Serial.begin(115200);
  cmdMessenger.printLfCr();
  attachCommandCallbacks();
}

void loop() {
  // put your main code here, to run repeatedly:
  cmdMessenger.feedinSerialData();
  if (digitalRead(5) != state)
    { 
      if(digitalRead(5))
        {
        CmdMessenger.sendCmd(kOn,"");
    }
      else{
          //CmdMessenger.sendCmd(kSetOff);
      }  
    }
  }
}
