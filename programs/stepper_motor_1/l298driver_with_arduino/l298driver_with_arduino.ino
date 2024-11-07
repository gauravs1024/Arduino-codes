#include<Stepper.h>
const int stepsPerRevolution=100;
Stepper myStepper(stepsPerRevolution,2,3,4,5);

void setup() {
 myStepper.setSpeed(300);
 Serial.begin(9600);


}

void loop() {
Serial.println("clockwise");
myStepper.step(stepsPerRevolution);
myStepper.step(stepsPerRevolution);
myStepper.step(stepsPerRevolution);

delay(500);
Serial.println("counterclockwise");
myStepper.step(-stepsPerRevolution);
myStepper.step(-stepsPerRevolution);
myStepper.step(-stepsPerRevolution);
delay(500);




}
