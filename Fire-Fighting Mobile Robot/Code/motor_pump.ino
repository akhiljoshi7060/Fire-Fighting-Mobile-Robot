int motor_pin = 2;  // This is for input pin
//int motor=HIGH;

void setup() 
{
pinMode(motor_pin, OUTPUT);
Serial.begin(9600);
}

void loop()
{
  digitalWrite(2,HIGH);
 delay(2000);
  digitalWrite(2,LOW);
  delay(2000);
}

