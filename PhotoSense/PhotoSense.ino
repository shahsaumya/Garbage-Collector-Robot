void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}
int val;

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0)
  val=Serial.read();
  if(val>150){
  digitalWrite(13, HIGH);
  }else{
    digitalWrite(13, LOW);
  }
}



  
