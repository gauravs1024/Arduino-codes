int enable_pin1=2;
 int output_pin1=5;
int  output_pin2=11;
int enable_pin2=3;
 int output_pin3=12;
 int output_pin4=13;
void setup() {
  // put your setup code here, to run once:
   pinMode(enable_pin1,OUTPUT);
   pinMode( output_pin1,OUTPUT);
   pinMode(output_pin2,OUTPUT);
   pinMode(enable_pin2,OUTPUT);
   pinMode(output_pin3,OUTPUT);
   pinMode(output_pin4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
analogWrite(enable_pin1,1023);
digitalWrite(output_pin1,HIGH);
digitalWrite(output_pin2,LOW);
analogWrite(enable_pin2,1023);
digitalWrite(output_pin3,HIGH);
digitalWrite(output_pin4,LOW);
delay(5000);
analogWrite(enable_pin1,1023);
digitalWrite(output_pin1,LOW);
digitalWrite(output_pin2,HIGH);
analogWrite(enable_pin2,1023);
digitalWrite(output_pin3,LOW);
digitalWrite(output_pin4,HIGH);
delay(5000);
}
