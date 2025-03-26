#include <WiFi.h>
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char WIFI_SSID[] = "Rudranarayan Sahu";
const char WIFI_PASSWORD[] = "P@ssw0rd";

// Device and Key from Arduino Cloud
const char DEVICE_ID[] = "1745db58-412c-480d-9ae9-ad0b6f11b86f";
const char DEVICE_SECRET[] = "gVX7QsN2gn5Bl?4Z9G3JSC4qZ";

int speed = 0;
String direction = "STOP";

// Motor Pins
const int IN1 = 27;
const int IN2 = 26;
const int IN3 = 25;
const int IN4 = 33;
const int ENA = 14;
const int ENB = 12;

void onSpeedChange() {
  analogWrite(ENA, speed);
  analogWrite(ENB, speed);
}

void onDirectionChange() {
  if (direction == "FORWARD") {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
  } else if (direction == "BACKWARD") {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
}

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");

  ArduinoCloud.begin(DEVICE_ID, DEVICE_SECRET);
  ArduinoCloud.addProperty(speed, READWRITE, ON_CHANGE, onSpeedChange);
  ArduinoCloud.addProperty(direction, READWRITE, ON_CHANGE, onDirectionChange);
}

void loop() {
  ArduinoCloud.update();
} 
