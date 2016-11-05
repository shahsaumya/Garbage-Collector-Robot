#define HM_1 12
#define HM_2 13
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  moveHeadDown();
  }
void moveHeadDown()
{
  digitalWrite(HM_1, LOW);              //move the DC motors
  digitalWrite(HM_2, HIGH);
  delay(3120);                          // allows head to come up for 4s
  digitalWrite(HM_1, LOW);              // stops the movement
  digitalWrite(HM_2, LOW);
  delay(4000);
}


void moveHeadUp(){
  digitalWrite(HM_1, HIGH);              //move the DC motors
  digitalWrite(HM_2, LOW);
  delay(3120);                          // allows head to come up for 4s
  digitalWrite(HM_1, LOW);              // stops the movement
  digitalWrite(HM_2, LOW);
  delay(4000);

}
