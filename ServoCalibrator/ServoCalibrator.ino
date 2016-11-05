# include<Servo.h>
Servo s1;
Servo s2;
void setup() {
  // put your setup code here, to run once:
s1.attach(10);
s2.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  s1.write(90);
  s2.write(90);
}
