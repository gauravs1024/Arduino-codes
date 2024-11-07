#include<ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WiFi.h>
WiFiClient client;
const char* ssid="";
const char* password="";
const char* URL="http://192.168.29.71/GAURAV/project_patient_monitoring/sends_sensor_data_database.php";
int pulse_sensor_reading=45;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  Serial.println("connectin");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print(" WIfi connected successfull");
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.localIP());


}

void loop() {
  // put your main code here, to run repeatedly:
if(WiFi.status()==WL_CONNECTED){
  HTTPClient http;
  http.begin(client,URL);
  http.addHeader("content-Type","application/x-www-form-urlencoded");
 // Serial.println();
 String httpRequestData ="pulse "+String(pulse_sensor_reading);
 Serial.print("httpRequestData:");
 Serial.print(httpRequestData);
 int httpResponseCode =http.POST(httpRequestData);
 if(httpResponseCode>0){
  Serial.print("HTTP REsponse code");
  Serial.print(httpResponseCode);

 }
else {
   Serial.print("Error code");
  Serial.print(httpResponseCode);

}
http.end();
  }

  else{
    Serial.println("WiFi Discoonected");
  }

delay(1000);


}
