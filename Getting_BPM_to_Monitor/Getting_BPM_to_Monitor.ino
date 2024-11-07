
#include <WiFi.h>
//#include <HTTPClient.h>
#include<ESP8266HTTPClient.h>
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   
WiFiClient client;


//  Variables
String URL="http://192.168.29.71/GAURAV/project_patient_monitoring/sends_sensor_data_database.php";
const int PulseWire = 0;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED = LED_BUILTIN;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 

const char* ssid="";
const char* password=""; 


int pulse_sensor_reading;
int myBPM;
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"


void setup() {   

  Serial.begin(115200);         // For Serial Monitor
  connectWiFi();  

  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);  
  

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}



void loop() {
  

if (pulseSensor.sawStartOfBeat()) {            // Constantly test to see if "a beat happened".
myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 
 Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");                        // Print phrase "BPM: " 
 Serial.println(myBPM);                        // Print the value inside of myBPM. 
}

pulse_sensor_reading=myBPM;
if(WiFi.status()!=WL_CONNECTED){
    connectWiFi();

  }
String postdata="pulse "+String(pulse_sensor_reading);
HTTPClient http;
http.begin(URL);

int httpcode=http.POST(postdata);//  if response code is 200 then tha data sent successfully
String payload=http.getString();
http.addHeader("Content-Type","application/x-www-form-urlencoded");
 
Serial.print("URL :");Serial.println(URL); 
Serial.print("DATA:");Serial.println(postdata); 
Serial.print("httpcode");Serial.println(httpcode); 
Serial.print("payload");Serial.println(payload); 



  delay(20);                    // considered best practice in a simple sketch.

}

void connectWiFi(){
  WiFi.mode(WIFI_OFF);
  delay(1000);
  // this line hides the viewing of esp as wifi hotspot
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  Serial.println("Connecting to WiFi...");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");

  }
  Serial.println("Connected to ");Serial.print(ssid);
  Serial.println("IP address: "); Serial.print(WiFi.localIP());
}

  
