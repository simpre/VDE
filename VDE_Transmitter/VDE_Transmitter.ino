#include <QueueList.h>
class Message{
  private:
  String mName;
  QueueList<String> ParameterQueue;

  public:  

  Message(String pName){
  mName = pName ;
  }  
  Message(){}
  void setName(String pName){
     mName = pName;    } 
  String  getName(){
    return mName;    }
  String  getNextParameter(){     
    return ParameterQueue.pop();
    
    }
  int     getNextIntParameter(){
    return getNextParameter().toInt();
    }
  void    appendParameter(String pParameter){
    ParameterQueue.push(pParameter);
    }
  boolean isEmpty (){
    return ParameterQueue.isEmpty();
    }
  String  MessageToString(){
    String temp = getName();
    while (!isEmpty()){
        temp = temp + " - ";
        temp =  temp + getNextParameter();
        
      }
      return temp;
    }
  void printToSerial() {
    Serial.println(getName());
    while (!isEmpty())
    {
    Serial.println(getNextParameter());
      }
    }
    void printIntToSerial() {
    Serial.println(getName());
    while (!isEmpty())
    {
    Serial.println(getNextIntParameter());
      }
    }
  };
class SerialHandler{
   private:
   
   String   inputString ; 
   Message  bufferMessage ;
   Message  tempMessage ;
   String   tempString;
   boolean  nameSet = false;
   boolean  messageInBuffer = false;
   
   public:
   SerialHandler(){ //Konstruktor      
   inputString.reserve(200);  // reserve 200 bytes for the inputString:
   }
   void     SerialIn(char a){
   inputString = inputString + a;
    }
   void     UpdateInput(){
   while((inputString.length() > 0) && (!messageInBuffer)){
      if(inputString.charAt(0)=='\a'){        
          String tempString = "";
          nameSet=false;
          tempMessage = Message();          
        }
      else if(inputString.charAt(0 =='\t')){
         if(nameSet){
          tempMessage.appendParameter(tempString);
          tempString = "";
          }
          else{
            tempMessage.setName(tempString);
            nameSet=true;
            tempString= "";
            }
        }
      else if(inputString.charAt(0 == '\n')){
         tempMessage.appendParameter(tempString);
         bufferMessage = tempMessage;
         messageInBuffer= true;
        }
      else {
        tempString = tempString + inputString.charAt(0);
        }
        tempString = tempString.substring(1);   
    }
    }
   Message  getNextMessage(){
    return bufferMessage;
    }
   void     sendMessage (Message pMessage){
    String temp = '\a' + pMessage.getName();
    while (!pMessage.isEmpty())
    {
        temp = temp + '\t' + pMessage.getNextParameter();
      }
    
    temp = temp + '\n' ;
    Serial.print(temp);
   }
  };

SerialHandler mSH;
void setup() {
  Serial.begin(9600);
  

}

void loop() {
  delay (2000);
  String a = "";
  a += '\a' ;
  a += "Befehl" ;
  a += '\t' ;
  a += "Par1" ;
  a += '\t';
  a += "Par2" ;
  a += '\n';
  

  Serial.print(a);
  Serial.print ("transmitted");

}
void serialEvent() {
  while (Serial.available()) {
    mSH.SerialIn((char)Serial.read());
  }
  mSH.UpdateInput();
  }
