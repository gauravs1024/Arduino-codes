#include<ESP8266WiFi.h>
WiFiClient client;
WiFiServer server(80);
#define led D4
void setup() {
  Serial.begin(9600);
  WiFi.softAP("NODEMCU","12345678");
  Serial.println();
  Serial.println("NODEMCU started");
  Serial.println(WiFi.softAPIP());
  server.begin();
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
client=server.available();
if(client==1){
  String request=client.readStringUntil('\n');
  Serial.println(request);
  request.trim();
  if(request=="GET /ledon HTTP/1.1")
  {
    digitalWrite(led,HIGH);
    
  }
}


digitalWrite(led,HIGH);
delay(1000);
digitalWrite(led,LOW);
delay(1000);

}
