#include <WiFi.h>  // for ESP-32 remove ESP8266 and just keep it <WiFi.h>

const char* ssid = "ERNET-INDIA";

const char* password = "Cisco@321";

int iled = 2;   // for nodemcu change it to 2.

void setup() {

  Serial.begin(115200);

  pinMode(iled,OUTPUT);

  WiFi.begin(ssid, password);

  Serial.println("Connecting");

  while(WiFi.status() != WL_CONNECTED) {

    digitalWrite(iled,HIGH);

    delay(5000);

    Serial.print(".");

  }

  Serial.println("");

  Serial.print("Connected to WiFi network with IP Address: ");

  Serial.println(WiFi.localIP());

}

void loop() {

  if(WiFi.status()== WL_CONNECTED){

    digitalWrite(iled,HIGH);

    delay(500);

    digitalWrite(iled,LOW);

    delay(500);

  }

  else{

     Serial.println("WiFi Disconnected");

     digitalWrite(iled,HIGH);

     delay(500);

  }

}