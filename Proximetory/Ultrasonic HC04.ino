#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 13
#define BUZZER_PIN 11

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    long duration;
    int distance;

    // Trigger the ultrasonic sensor
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Read the echo time and calculate distance
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // If an object is detected within 20 cm
    if (distance > 0 && distance <= 20) {
        digitalWrite(LED_PIN, HIGH);
        tone(BUZZER_PIN, 1000);  // Buzzer ON
    } else {
        digitalWrite(LED_PIN, LOW);
        noTone(BUZZER_PIN);  // Buzzer OFF
    }

    delay(500);
}
