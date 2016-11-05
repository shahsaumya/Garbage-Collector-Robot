#include<Servo.h>
#define LM_1 2
#define LM_2 4
#define RM_1 7
#define RM_2 8
#define HM_1 12  // motors for the head connected to H-bridge
#define HM_2 13
#define MIN_VAL 10
#define MAX_VAL 270
#define THR 15
#define MID_VAL 150
#define PROX 3
#define EM_PIN 5
#define SHOULDER 10
#define ELBOW 9
#define SHOULDER2 11
Servo shoulder;
Servo elbow;
Servo shoulder2;
int shoulderPos = 90;
int elbowPos = 90;
int shoulder2Pos = 90;
boolean key = true;
boolean key2 = true;
boolean prox;
boolean keytrans = true;
boolean key3=true;
int pos;

void moveServo(Servo servo, int init, int fin){
  for(int i=init; !((i-fin)==0); i+=increment(init, fin)){
    servo.write(i);
    delay(15);
  }
}

void packup()
{

  moveServo(shoulder, 90, 130);
  moveServo(shoulder2 , 90, 60);
  delay(2000);
  moveHeadDown();
  delay(1000);
  moveServo(shoulder, 130, 180);
  moveServo(shoulder2, 60 , 0 );
}
void moveHeadDown()
{
  digitalWrite(HM_1, LOW);              //move the DC motors
  digitalWrite(HM_2, HIGH);
  delay(4000);                          // allows head to come up for 4s
  digitalWrite(HM_1, LOW);              // stops the movement
  digitalWrite(HM_2, LOW);
}


void moveHeadUp(){
  digitalWrite(HM_1, HIGH);              //move the DC motors
  digitalWrite(HM_2, LOW);
  delay(4000);                          // allows head to come up for 4s
  digitalWrite(HM_1, LOW);              // stops the movement
  digitalWrite(HM_2, LOW);
}

int increment(int initial, int fin)
{
  if(initial<=fin)
    return 1;
  else 
    return -1;
}
void moveArm(){
  moveServo(shoulder, 0 ,  90);
  moveServo(elbow, 90, 37);
  startEM();
  delay(2000);
  moveServo(elbow, 37, 127);

  delay(2000);
  moveServo(shoulder, 90, 130);

  stopEM();
  delay(2000);
  moveServo(shoulder, 130, 90);
  moveServo(elbow, 127, 90);

}

void startEM()
{
  digitalWrite(EM_PIN, HIGH);

}

void stopEM()

{
  digitalWrite(EM_PIN, LOW);
}
void moveForward()
{
  digitalWrite(LM_1, LOW);
  digitalWrite(LM_2, HIGH);
  digitalWrite(RM_1, HIGH);
  digitalWrite(RM_2, LOW);

}

void turnRight()
{
  digitalWrite(LM_1, LOW);
  digitalWrite(LM_2, HIGH);
  digitalWrite(RM_1, LOW);
  digitalWrite(RM_2, HIGH);
}

void turnLeft()
{
  digitalWrite(LM_1, HIGH);
  digitalWrite(LM_2, LOW);
  digitalWrite(RM_1, HIGH);
  digitalWrite(RM_2, LOW);
}

void stopMoving()
{
  digitalWrite(LM_1, LOW);
  digitalWrite(LM_2, LOW);
  digitalWrite(RM_1, LOW);
  digitalWrite(RM_2, LOW);
}

boolean getProx()
{
  if (digitalRead(PROX)==HIGH)
    return true;
  else
    return false;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LM_1, OUTPUT);
  pinMode(LM_2, OUTPUT);
  pinMode(RM_1, OUTPUT);
  pinMode(RM_2, OUTPUT);
  shoulder.attach(SHOULDER);
  elbow.attach(ELBOW);
  shoulder2.attach(SHOULDER2);
  Serial.begin(9600);
  pinMode(HM_1,OUTPUT);
  pinMode(HM_2,OUTPUT);
  shoulder2.write(60);
  shoulder.write(130);
  moveServo(shoulder2, 60, 180); 
  moveServo(shoulder, 130, 0);
  //moveServo(elbow, 130, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  elbow.write(90);
   if(keytrans == true)
   {
   
   for(int i = 0; !((0-i)==0); i+=increment(90,0))
   { shoulder.write(i);
   shoulder2.write(i);
   delay(5);
   }
   delay(2000);
   moveHeadUp();
   stopMoving();
   keytrans = false;
   }
  if ((Serial.available() > 0)) {
    pos = Serial.read();

    if (pos == 0)
    {
      turnLeft();
    }
    else if (pos > MIN_VAL && pos < MID_VAL - THR) {
      turnLeft();
    }

    else if (pos > MID_VAL + THR && pos < MAX_VAL) {
      turnRight();
    }

    else {
      stopMoving();
      if(key3){
      prox = getProx();
      if(key2)
      {
        if(prox)
          moveForward();
         else
         key2=false;
      }

      else
      {  stopMoving();
      moveArm();
      delay(5000);
      
      packup();
    key3=false;}}
    }   
  }

}





