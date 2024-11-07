#include<WiFi.h>
#include<HTTPClient.h>
String URL="http://192.168.43.133/GAURAV/project_patient_monitoring/sends_sensor_data_database.php?pulse=99";




void setup() {
  // put your setup code here, to run once:

  callAPI();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void setupWIFI(){
  char* ssid="Redmi Note 7S";
  char* password="123456789";
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.print("\nconnecting");
  while(WiFi.status()==WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }

  Serial.print("\Connected to the wifi network"+String(ssid));
  Serial.print("Local IP:");
  Serial.println(WiFi.localIP());
}

void callAPI(){
  Serial.println("Calling Api....");
  if(WiFi.status()==WL_CONNECTED){
    HTTPClient http;
    WiFiClient client;
    http.begin(client,URL);
    http.addHeader("content-Type","application/x-www-form-urlencoded");
  int httpresponsecode=http.GET();
 
  
  if(httpresponsecode>0){
  String payload=http.getString();
  Serial.println(payload);
  Serial.print("httpresponse code:");
  Serial.println(httpresponsecode);
  }
  else{
    Serial.print("Error code");
    Serial.println(htt
    
  }
  http.end();
}

else{
  Serial.println("WiFi Disconnected");
}
}
