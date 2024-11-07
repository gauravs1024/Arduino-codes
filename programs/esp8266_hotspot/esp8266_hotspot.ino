#include<ESP8266WiFi.h>


void setup() {
  // put your setup code here, to run once:
WiFi.begin("Nextup Robotics 5","King@123");
while(WiFi.status()!=WL_CONNECTED)
{
  Serial.println("connecting...");
  delay(200);
}

Serial.println("NODEMCU is connected succesfully");
Serial.println(WiFi.localIP());


}

void loop() {
  // put your main code here, to run repeatedly:

}
