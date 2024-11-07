int echo =9;
int trig=8;


void setup() {
  // put your setup code here, to run once:
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);
}

long duration;
int distance;
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  
  Serial.print(distance);
  Serial.print("cm\n");
  

}
