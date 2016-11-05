
#define IN1 2
#define IN2 4
#define IN3 7
#define IN4 8

void moveForwardM1()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void moveBackwardM2()
{
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackwardM1()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}
void stopMovingM1()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void stopMovingM2()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void moveForwardM2()
{
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
   moveForwardM2();
  delay(5000);
  stopMovingM2();

  moveForwardM1();
  delay(4800);
  stopMovingM1();
  delay(10000);
  
  moveBackwardM2();
  delay(5000);
  stopMovingM2();

  moveBackwardM1();
  delay(4800);
  stopMovingM1();
  delay(10000);
}




