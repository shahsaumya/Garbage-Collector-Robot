#define LM_1 2
#define LM_2 3
#define RM_1 4
#define RM_2 5

#define MIN_VAL 10
#define MAX_VAL 270
#define THR 15
#define MID_VAL 150
#define PROX 3


//boolean key = true;
boolean key2 = true;;
boolean prox;
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
    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
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
   if(!prox)
   moveForward();
  }

  else
  stopMoving();
      
    }   
  }
   

}
