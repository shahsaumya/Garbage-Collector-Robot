
#define LM_1 2  //pin 2
#define LM_2 4  //pin 4
boolean key2 = true;
//right motor
#define RM_1 7  //pin 7
#define RM_2 8  //pin 8
#define PROX 3

boolean getProx()
  {
    if (digitalRead(PROX)==HIGH)
    return true;
    else
    return false;
  }
void moveForward()
{
  digitalWrite(LM_1, LOW);
  digitalWrite(LM_2, HIGH);
  digitalWrite(RM_1, HIGH);
  digitalWrite(RM_2, LOW);

}

void moveBackward()
{
  digitalWrite(LM_2, LOW);
  digitalWrite(LM_1, HIGH);
  digitalWrite(RM_2, HIGH);
  digitalWrite(RM_1, LOW);
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
  pinMode(RM_1, OUTPUT);
  pinMode(RM_2, OUTPUT);
  pinMode(PROX, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(key2){
    //moves forward
    
    if(getProx())
    moveForward();

    //disables movement when object is reached
    if(!getProx()){
      key2=false;
      stopMoving();
      delay(100);
      moveBackward();
      delay(100);
      stopMoving();
    }
  }
}
