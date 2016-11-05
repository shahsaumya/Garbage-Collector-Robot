#include<Servo.h>
#define SHOULDER 9
#define SHOULDER2 10
#define ELBOW 11
Servo shoulder;
Servo elbow;
Servo shoulder2;

//define the pins
#define LM_1 2
#define LM_2 3
#define RM_1 4
#define RM_2 5
#define ELECTRO_MAGNET 16
#define HLM_1 2  // motors for the head connected to H-bridge
#define HLM_2 3
#define HRM_1 4
#define HLM_2 5
//defining constants
#define MIN_VAL 10
#define MAX_VAL 270
#define THR 20
#define MID_VAL 150

boolean key = true;
boolean key2 = false;
boolean prox, disable;
boolean keytrans = true;
int pos;


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
    digitalWrite(LM_2, LOW);        // left wheel is stationary
    digitalWrite(RM_1, LOW);
    digitalWrite(RM_2, HIGH);
  }

  void turnLeft()
  {
    digitalWrite(LM_1, HIGH);
    digitalWrite(LM_2, LOW);
    digitalWrite(RM_1, LOW);                // right motor is stationery
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

    pinMode(LM_1, OUTPUT);
    pinMode(LM_2, OUTPUT);
    pinMode(RM_1, OUTPUT);
    pinMode(RM_2, OUTPUT);
    pinMode(HLM_1, OUTPUT);
    pinMode(HLM_2, OUTPUT);
    pinMode(HRM_1, OUTPUT);
    pinMode(HRM_2, OUTPUT);    
    shoulder.attach(SHOULDER);
    elbow.attach(ELBOW);
    Serial.begin(9600);
    shoulder2.attach(SHOULDER2);

  }
void moveArm(){
  shoulder.write(POS_1);
  delay(2000);
  elbow.write(POS_E_1);
  delay(2000);
  startEM();
  elbow.write(POS_E_2);
  delay(2000);
  shoulder.write(POS_2);
  delay(3000);
  stopEM();
}


  void startEM()
  {
    digitalWrite(ELECTRO_MAGNET, HIGH);

  }

  void stopEM()

  {
    digitalWrite(ELECTRO_MAGNET, LOW);
  }
  void moveHead(){
    digitalWrite(HLM_1, LOW);              //move the DC motors
    digitalWrite(HLM_2, HIGH);
    digitalWrite(HRM_1, HIGH);
    digitalWrite(HRM_2, LOW);
    delay(4000);                          // allows head to come up for 4s
    digitalWrite(LM_1, LOW);              // stops the movement
    digitalWrite(LM_2, LOW);
    digitalWrite(RM_1, LOW);
    digitalWrite(RM_2, LOW);
    
    }

  boolean getProx()
  {
    if (digitalRead(PROX_PIN)==HIGH)
    return true;
    else
    return false;
  }
  void loop() 
  
  {

    if(keytrans == true)
    {

      shoulder.write(Trans_POS);
      delay(2000);
      shoulder2.write(Trans_POS)
      delay(2000);
      keytrans = false;
      
    }
    
    if ((Serial.available() > 0) && key) {
      pos = Serial.read();
    
    if ((pos == 0)
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
      key = false;
      key2 = true;
    }   
  }

   prox = getProx();
  if(key2)
  {
  
    if(!prox)
   moveForward();
  else
    {stopMoving();
    moveArm();
    disable = true;
    } 

  }

  if(disable)
  {
    delay(10000);
    packup();

  }

void packup()
{
  elbow.write(RETRACT_POS);
  shoulder.write(Trans_FINALPOS);
  shoulder2.write(-(TRANS_POS));
}

}

