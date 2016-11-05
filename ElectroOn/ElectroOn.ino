
#include <Servo.h>
Servo shoulder;

void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
digitalWrite(5, HIGH);
shoulder.attach(10);
}

int increment(int initial, int fin)
{
  if(initial<=fin)
  return 1;
  else 
  return -1;
}
void moveServo(Servo servo, int init, int fin){
    for(int i=init; !((i-fin)==0);i+=increment(init,fin)){
        servo.write(i);
        delay(15);
      }
  }

void loop() {
  // put your main code here, to run repeatedly:
moveServo(shoulder,90,125); 
delay(500);
digitalWrite(5, LOW);
}
