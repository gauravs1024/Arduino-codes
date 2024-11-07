#include <SoftwareSerial.h>

SoftwareSerial espSerial(10, 11); // RX (Arduino) -> TX (ESP-01), TX (Arduino) -> RX (ESP-01)

void setup() {
  Serial.begin(115200);    // Serial Monitor for debugging
  espSerial.begin(115200); // ESP-01 communication
   espSerial.println("AT"); // Forward data from Serial Monitor to ESP-01
   delay(2000);
     espSerial.println("AT+GMR");
      delay(2000);
  espSerial.println("AT+CWMODE=1");
   delay(2000);
  espSerial.println("AT+CWLAP");
   delay(2000);
    espSerial.println("AT+CWJAP=\"Universe\",\"gaurav@123\"");
     delay(6000);
     if(Serial.readString()=="OK")
     Serial.println("connected");
     else
      Serial.println(" not connected");
}

void loop() {


  
  
   
  
}
