 #include<Servo.h>
#define SHOULDER 10
#define ELBOW 9
Servo shoulder;
Servo elbow;
boolean keyarm = true;
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
void moveArm(){
 moveServo(elbow,90,37);
 delay(2000);
moveServo(elbow,37,120);
  delay(2000);
moveServo(shoulder,90,125); 

}


void setup() {
  // put your setup code here, to run once:

shoulder.attach(SHOULDER);
elbow.attach(ELBOW);
elbow.write(90);
shoulder.write(90);
delay(1500);
digitalWrite(4, HIGH);
}
void loop() {
  
  while(keyarm)
  {
  moveArm();
  keyarm = false;
  }
  // put your main code here, to run repeatedly:

}
