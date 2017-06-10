class Motor 
{
boolean       forward = false ;
int           m_speed =0;
volatile int           cnt = 0;

unsigned long systime ;
unsigned long old_systime ;

int           M0_pin;
int           M1_pin;
int           interrupt_pin;
int           tach_pin;


Motor(int p_M0_pin, int p_M1_pin, int p_interrupt_pin ,int p_tach_pin)
{
    M0_pin        = p_M0_pin;
    M1_pin        = p_M0_pin;
    interrupt_pin = p_interrupt_pin ;
    tach_pin      = p_tach_pin; 
    attachInterrupt(digitalPinToInterrupt(interrupt_pin),count,RISING );
}
void turn(boolean forward, int mspeed )
{
  if(forward)
  {
    analogWrite(M0_pin, mspeed);
    analogWrite(M1_pin, 0);
    }
  else { 

    analogWrite(M1_pin, mspeed);
    analogWrite(M0_pin, 0);
}
}

int getspeed()
{
  return m_speed;
  }
 void count()
{
  cnt ++;
  }
void update_speed()
{
    m_speed = (systime - millis())/cnt;
    cnt = 0;
    systime =millis();
}

};

Motor m = new Motor(9,10,2,4);

void setup ()
{
 Serial.begin(9600); 
  }

void loop()
{
  delay(1000);
  Serial.println(m.getspeed());
  }
