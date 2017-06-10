class Comunicator{
  class Befehl {
String befehlsname ="";
String Parameter[5] ; 
int   Parameternum  = 0;
Befehl(String befname){
  befehlsname = befname;
  }
void SetBefehl(String p ){
   befehlsname = p ;
  }
void addparameter(String i){
    if(Parameternum<5)
    {
      Parameter[Parameternum] = i; 
      }
} 
String getParameter(int i ){
  if(i<5)
  {
      return Parameter[i];
  }
  return "";
}
String getBefehl(){
    return befehlsname;
  }
};


};
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
