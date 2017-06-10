#include <QueueList.h>
class Message{
  private:
  static String mName;
  QueueList<String> ParameterQueue;
  static boolean isQueueEmpty; 
  public:  
  Message(String pName){
  mName = pName ;
  isQueueEmpty = true;
  }
  Message(){
    isQueueEmpty = true;
    mName = "";
    }
  void setName(String pName){
     mName = pName;    } 
  String  getName(){
    return mName;    }
  String  getNextParameter(){
    if (ParameterQueue.count()<=1) {isQueueEmpty = true;} 
    return ParameterQueue.pop();
    
    }
  int     getNextIntParameter(){
    return getNextParameter().toInt();
    }
  void    appendParameter(String pParameter){
    ParameterQueue.push(pParameter);
    isQueueEmpty = false;
    }
  boolean isEmpty (){
    return isQueueEmpty;
    }
  String  toString(){
    String temp = mName;
    while (!isEmpty()){
        temp += " - ";
        temp += getNextParameter();
        
      }
    }
};

/*class SerialHandler{
   private:
   QueueList<Message> InputQueue;
   String   inputString ; 
   Message  tempMessage ;
   String   tempString;
   boolean  nameSet = false;
   
   public:
   SerialHandler(){ //Konstruktor      
   inputString.reserve(200);  // reserve 200 bytes for the inputString:
   tempMessage.setName("asdf");
   }
   void     SerialIn(char a){
   inputString += a;
    }
   void     UpdateInput(){
   while(inputString.length() > 0){
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
            }
        }
      else if(inputString.charAt(0 == '\n')){
         tempMessage.appendParameter(tempString);
         InputQueue.push(tempMessage);
        }
      else {
        tempString += inputString.charAt(0);
        }
    tempString = tempString.substring(1);   
    }
    }
   Message  getNextMessage(){
    InputQueue.pop();
    }
 /*  void     SendMessage (Message pMessage){
    String temp = "";
    temp = temp + '\a' ;
    temp = temp + pMessage.getName();
    pMessage.getName();
    while (!pMessage.isEmpty())
    {
        temp = temp +'\t';
        temp = temp + pMessage.getNextParameter();
      }
      temp = temp + '\n';
     // Serial.print(temp);
    }
   void     appendMessage(Message pMessage){
      InputQueue.push(pMessage);
    }
  };*/


//SerialHandler mSH;

void setup() {
  Serial.begin(9600); // initialize serial:
  Message a ("Hey");
  a.appendParameter("ES");
  a.appendParameter("Funktioniert");
 // mSH.appendMessage(a);
  //String asdf = mSH.getNextMessage().toString();
//  Serial.print(asdf);
}
void loop() {
  // put your main code here, to run repeatedly:

}
void serialEvent() {
  while (Serial.available()) {
//    mSH.SerialIn((char)Serial.read());
  }
//  mSH.UpdateInput();
  }
