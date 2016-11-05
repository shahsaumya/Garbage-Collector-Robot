#define LM_1 2
#define LM_2 4
#define RM_1 7
#define RM_2 8

#define MIN_VAL 10
#define MAX_VAL 270
#define THR 20
#define MID_VAL 150
#define PROX_PIN 6
#define MIN_DIST 10
boolean key = true;
boolean key2 = false;
boolean prox;
int pos;
#define TRIG 3
#define ECHO 6

int getDist()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(ECHO, HIGH);

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

void setup() {
  // put your setup code here, to run once:
  pinMode(LM_1, OUTPUT);
    pinMode(LM_2, OUTPUT);
    pinMode(RM_2, OUTPUT);
    pinMode(RM_1, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
      pinMode(ECHO, INPUT);
    pinMode(TRIG, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if (Serial.available() > 0) {
      pos = Serial.read();
    
    if (pos == 0)
  {
    turnLeft();
    digitalWrite(13, HIGH);
    }
    else if (pos > MIN_VAL && pos < MID_VAL - THR) {
    turnLeft();
    }
    
    else if (pos > MID_VAL + THR && pos < MAX_VAL) {
    turnRight();
    }
    
    else {
      stopMoving();
      key = false;
      key2 = true;
    }   
}
   if(key2)
   {
   if(getDist() > MIN_DIST)
   moveForward();
   else
   key2 = false;
   }
  else
  {
  stopMoving();
  key2 = false;}
}

