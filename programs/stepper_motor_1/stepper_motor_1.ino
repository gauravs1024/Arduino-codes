int steppin=3,dirpin= 2,enpin=6;
void setup() {
  
  // put your setup code here, to run once:
  pinMode(steppin,OUTPUT);
  pinMode(dirpin,OUTPUT);
  pinMode(enpin,OUTPUT);
  digitalWrite(enpin,OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(enpin,LOW);
  digitalWrite(dirpin,LOW);
  for(int i=0;i<4800;i++)
  {
    digitalWrite(steppin,HIGH);
    delayMicroseconds(500);
    digitalWrite(steppin,LOW);
       delayMicroseconds(500);

    }
  delay(1000);
 
}
  
