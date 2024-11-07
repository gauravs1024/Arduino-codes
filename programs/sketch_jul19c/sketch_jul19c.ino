
//for right
int enable1 =10;
int a=6;
int b= 5;
//for left
int enable2= 11;
int c=8;
int d= 9;
//for setup
void setup()
{
  pinMode(enable1,OUTPUT); 
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(enable2,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT); 
}
void loop(){
  digitalWrite(enable1, 100);
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(enable2, 100);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
}
