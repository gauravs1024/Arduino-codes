

// for  ultra sonic sensor
int echo =9;
int trig=8;


// for motor 1
int enableA=2; 
int in1=5;
int in2=11;
// for motor 2
int enableB=3;
int in3=12;
int in4=13;
//void left_wheel(int,int);
//void right_wheel(int, int);

void setup() {
  pinMode(enableA,OUTPUT);
  pinMode(enableB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
  
}
void right_wheel(int dir , int speed){
  if(dir==1){
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(enableA,speed);
  }
  else if(dir==-1){
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  analogWrite(enableA,speed);
  }
  else{
    analogWrite(enableA,0);// to stop the motor
  }
}



  void left_wheel(int dir , int speed){
  if(dir==1){
  digitalWrite(in4,HIGH);
  digitalWrite(in3,LOW);
  analogWrite(enableB,speed);
  }
  else if(dir==-1){
  digitalWrite(in4,LOW);
  digitalWrite(in3,HIGH);
  analogWrite(enableB,speed);
  }
  else{
    analogWrite(enableB,0);// to stop the motor
  }
  
}
float ultra_sonic_sensor(){
  long duration;
  float measured_distance;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  measured_distance=duration*0.034/2;
  
//  Serial.print(distance);
//  Serial.print("cm\n");
  return measured_distance;
  
}
void forward_move(){
  left_wheel(1,100);
  right_wheel(1,100);
  
}
void backward_move(){
  left_wheel(-1,100);
  right_wheel(-1,100);
}
void left_turn(){
  left_wheel(1,50);
  right_wheel(1,100);
  
}
void right_turn(){
  left_wheel(1,100);
  right_wheel(1,50);
  
}
void Break(){
  left_wheel(0,0);
  right_wheel(0,0);
}
float distance;
void loop() {
//  distance=ultra_sonic_sensor();
//  forward_move();
//  if(distance<=10){
  backward_move();
  delay(100);
  Break();
  delay(1000);
  backward_move();
delay(500);
forward_move();
delay(100);
Break();
delay(1000);
left_turn();
delay(200);
Break();
  delay(1000);
  


//distance=ultra_sonic_sensor();
Serial.print(distance);
Serial.print("cm\n");
  }
  

  
  
