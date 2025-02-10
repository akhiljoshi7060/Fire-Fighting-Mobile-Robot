#include<Servo.h>

int left_motor_forward = 5 ;
int left_motor_reverse = 4 ;
int right_motor_forward = 8;
int right_motor_reverse = 9 ;

int enable_left = 12;
int enable_right = 7;

#define rightMotorF 47
#define rightMotorB 49 

int FlamePin1 = 10; //This is for flame sensor1
int FlamePin2 = 11; //This is for flame sensor2
int FlamePin3 = 13;// This is for flame sensor3

int Flame1 = HIGH;  // HIGH when FLAME Exposed
int Flame2 = HIGH;  // HIGH when FLAME Exposed
int Flame3 = HIGH;  // HIGH when FLAME Exposed

Servo servo_m;

int left_sensor0 = A0 ;
int left_sensor1 =  A1 ;
int left_sensor2 = A2 ;
int right_sensor3 = A3 ;
int right_sensor4 = A4  ;
int right_sensor5 =A5 ;

void setup()
{
  servo_m.attach(6 );
 
  pinMode(left_sensor0,INPUT);
  pinMode(left_sensor1,INPUT);
  pinMode(left_sensor2,INPUT);
  pinMode(right_sensor3,INPUT);
  pinMode(right_sensor4,INPUT);
  pinMode(right_sensor5,INPUT);

  pinMode(left_motor_forward,OUTPUT);
  pinMode(left_motor_reverse,OUTPUT);
  pinMode(right_motor_forward,OUTPUT);
  pinMode(right_motor_reverse,OUTPUT);

  pinMode(rightMotorF, OUTPUT);
  pinMode(rightMotorB, OUTPUT);
  
  pinMode(FlamePin1, INPUT);
  pinMode(FlamePin2, INPUT);
  pinMode(FlamePin3, INPUT);
    
   Serial.begin(115200);
}

void loop()
{ 
  digitalWrite(enable_left,HIGH);
  digitalWrite(enable_right,HIGH);

  int ls0 = analogRead(left_sensor0);
  int ls1 = analogRead(left_sensor1);
  int ls2 = analogRead(left_sensor2);
  int rs3 = analogRead(right_sensor3);
  int rs4 = analogRead(right_sensor4);
  int rs5 = analogRead(right_sensor5);

if(ls0 >= 300  && rs5 >= 300  )
{
  analogWrite(left_motor_forward,240);
  analogWrite(left_motor_reverse,0);
  analogWrite(right_motor_forward,240);
  analogWrite(right_motor_reverse,0);
}
else if(ls0 >=300 && rs5 <=300 )
{
  analogWrite(left_motor_forward,0);
  analogWrite(left_motor_reverse,0);
  analogWrite(right_motor_forward,240);
  analogWrite(right_motor_reverse,0);
}
else if(ls0 <=300 && rs5 >= 300 )
{ 
  analogWrite(left_motor_forward,240);
  analogWrite(left_motor_reverse,0);
  analogWrite(right_motor_forward,0);
  analogWrite(right_motor_reverse,0);
}
else if(ls0 < 300 && ls1 <300 && ls2 <300 && rs3 < 300 && rs4 <300 && rs5 <300) 
{
  analogWrite(left_motor_forward,LOW);
  analogWrite(left_motor_reverse,LOW);
  analogWrite(right_motor_forward,LOW);
  analogWrite(right_motor_reverse,LOW);
  
  fire_fight();
}
else 
{
  analogWrite(left_motor_forward,240);
  analogWrite(left_motor_reverse,0);
  analogWrite(right_motor_forward,240);
  analogWrite(right_motor_reverse,0);
}
}
   void fire_fight()
{
  int j=45;
  for(int i=0;i<5;i++)
  { 
    servo_m.write(i*j);
    delay(2000);
    
    Flame1=digitalRead(FlamePin1);
    Flame2=digitalRead(FlamePin2);
    Flame3=digitalRead(FlamePin3);
    
   if(Flame1== LOW || Flame2 == LOW || Flame3 == LOW)//flame detected
  {
      digitalWrite(rightMotorF, HIGH);
      digitalWrite(rightMotorB, LOW);
      delay(5000);
  }
  else
  {
      digitalWrite(rightMotorF, LOW);
      digitalWrite(rightMotorB, LOW);
      delay(1000);
  }
}
}

