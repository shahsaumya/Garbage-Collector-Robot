boolean keytrans = true;
#include<Servo.h>
#define SHOULDER 9
#define SHOULDER2 10
#define ELBOW 11
#define HM_1 2  // motors for the head connected to H-bridge
#define HM_2 3
#define LM_1 2
#define LM_2 3
#define RM_1 4
#define RM_2 5
int fin, initial;
Servo shoulder;
Servo elbow;
Servo shoulder2;
int increment(int initial, int fin)
{
  if(initial<=fin)
  return 1;
  else 
  return -1;
}

void packup()
{
  
   for(int i = 0; !((fin-i)==0); i+=increment(0,90))
      { shoulder.write(i);
        shoulder2.write(i);
        delay(5);
      }
      delay(2000);
      moveHeadDown();
}
  void moveHeadDown()
  {
    digitalWrite(HM_1, HIGH);              //move the DC motors
    digitalWrite(HM_2, LOW);
    delay(4000);                          // allows head to come up for 4s
    digitalWrite(HM_1, LOW);              // stops the movement
    digitalWrite(HM_2, LOW);
  }


  void moveHeadUp(){
    digitalWrite(HM_1, LOW);              //move the DC motors
    digitalWrite(HM_2, HIGH);
    delay(4000);                          // allows head to come up for 4s
    digitalWrite(HM_1, LOW);              // stops the movement
    digitalWrite(HM_2, LOW);
    }

void setup() {
  // put your setup code here, to run once:
    shoulder.attach(SHOULDER);
    elbow.attach(ELBOW);
    shoulder2.attach(SHOULDER2);
    pinMode(LM_1,OUTPUT);
    pinMode(LM_2,OUTPUT);
    pinMode(RM_1,OUTPUT);
    pinMode(RM_2,OUTPUT);
    pinMode(HM_1,OUTPUT);
    pinMode(HM_2,OUTPUT);
    shoulder.write(90);
    shoulder2.write(90);
    elbow.write(90);
}


void loop() {
  // put your main code here, to run repeatedly:
    elbow.write(90);
    if(keytrans == true)
    {

       for(int i = 0; !((fin-i)==0); i+=increment(90,0))
      { shoulder.write(i);
        shoulder2.write(i);
        delay(5);
      }
      delay(2000);
      moveHeadUp();
      delay(10000);
      packup();
      keytrans = false;
      
    }
}
