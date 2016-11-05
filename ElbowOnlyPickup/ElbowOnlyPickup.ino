# include<Servo.h>
# define ELBOW 9
Servo elbow;
void setup() {
  // put your setup code here, to run once:
elbow.attach(ELBOW);
}

 int increment(int initial, int fin)
{
  if(initial<=fin)
  return 1;
  else 
  return -1;
}

  void startEM()
  {
    digitalWrite(11, HIGH);

  }
  
void loop() {
  // put your main code here, to run repeatedly:
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
  delay(8000);
}
