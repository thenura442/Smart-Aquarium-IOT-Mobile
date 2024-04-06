#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>

#define FIREBASE_HOST "finaldb-7ec97-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "IuD3Ld05i9Y4BngDBj0QrHc6WhiGVzGqdntLcFgS"
#define WIFI_SSID "Hansana" 
#define WIFI_PASSWORD "devakie73"

//////
#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS D2

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

float Celsius = 0;
float Fahrenheit = 0;
////////
const int trigPin=D4;
 const int echoPin=D5;
  long duration;
  int distance;

int ldr;
void setup() {
  // put your setup code here, to run once:
  sensors.begin();
  Serial.begin(9600);
/////////////  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("connected");
  }
  delay(500);
  ////////

  pinMode(D1,INPUT);
  pinMode(D7,OUTPUT);

  /////////

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
  
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  /////////

}

void loop() {
    // set  temp sensor
  Firebase.setFloat("temperature", sensors);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /temperature failed:");
    Serial.println(Firebase.error());
    return;
}
  // ldr 
  int ldr= digitalRead(D1);
  
  if(ldr==0) {
    digitalWrite(D7,LOW);
   }else{
    digitalWrite(D7,HIGH);}

     // set  ldr
  Firebase.setInt("light",ldr);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /temperature failed:");
    Serial.println(Firebase.error());
    return;

    //////// append a new value to /logs
    String name = Firebase.pushInt("logs", n++);
    // handle error
    if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
    }
    Serial.println(Firebase.error());
    return;
    
    Serial.print("pushed: /logs/");
    Serial.println(name);
    delay(1000);
    /////////////////

     sensors.requestTemperatures();

  Celsius = sensors.getTempCByIndex(0);
  Fahrenheit = sensors.toFahrenheit(Celsius);

  

  delay(1000);

      
  
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration*0.034/2;

  // set  ultrasonic
  Firebase.setInt("distance",distance);
  // handle error
  if (Firebase.failed()) {
    Serial.print("setting /temperature failed:");
    Serial.println(Firebase.error());
    return;
  
}
