#include <Servo.h>
Servo shoulder;
   
 int increment(int initial, int fin)
{
  if(initial<=fin)
  return 1;
  else 
  return -1;
}
void stopEM()

  {
    digitalWrite(11, LOW);
  }
void setup() {
  // put your setup code here, to run once:
shoulder.attach(9);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; !((120-i)==0); i+=increment(0,120))
 { shoulder.write(i);
  delay(5);
 }
 stopEM();
 delay(2000);
  for(int i = 0; !((0-i)==0); i+=increment(120,0))
 { shoulder.write(i);
  delay(5);
 }
 
}
