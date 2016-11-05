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
#define TRIG 3
#define ECHO 6
#define EM_PIN 5
#define SHOULDER 10
#define ELBOW 9
#define SHOULDER2 11
#define MIN_DIST 10
Servo shoulder;
Servo elbow;
Servo shoulder2;

//boolean key = true;
boolean key2 = true;;
boolean prox;
boolean keytrans = true;
int pos;
int getDist()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  return cm;
  //delay(5);
}


long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}


void packup()
{
  
   for(int i = 0; !((90-i)==0); i+=increment(0,90))
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
    
 int increment(int initial, int fin)
{
  if(initial<=fin)
  return 1;
  else 
  return -1;
}
void moveArm(){
  for(int i = 0; !((40-i)==0); i+=increment(90,40))
 { elbow.write(i);
  delay(5);
 }
 startEM();
 delay(2000);
 for(int i = 0; !((90-i)==0); i+=increment(40,90))
 { elbow.write(i);
  delay(5);
 }
  delay(2000);
  for(int i = 0; !((105-i)==0); i+=increment(0,105))
 { shoulder.write(i);
  delay(5);
 }
 stopEM();
 
}

  void startEM()
  {
    digitalWrite(11, HIGH);

  }

  void stopEM()

  {
    digitalWrite(11, LOW);
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
    shoulder.attach(SHOULDER);
    elbow.attach(ELBOW);
    shoulder2.attach(SHOULDER2);
    pinMode(11,OUTPUT);
    Serial.begin(9600);
    pinMode(HM_1,OUTPUT);
    pinMode(HM_2,OUTPUT);
}

    void loop() {
      // put your main code here, to run repeatedly:
      elbow.write(90);
        if(keytrans == true)
        {
    
           for(int i = 0; !((0-i)==0); i+=increment(90,0))
          { shoulder.write(i);
            delay(5);
          }
            for(int i = 0; !((0-i)==0); i+=increment(90,0))
          { shoulder2.write(i);
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
          prox = getProx();
             if(key2)
            {
             if(getDist()>MIN_DIST)
             moveForward();
            }
          
            else
            stopMoving();
            moveArm();
            delay(5000);
            packup();}   
      }
    
    }




