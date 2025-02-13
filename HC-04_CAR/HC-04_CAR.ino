#include <Servo.h>

#define TRIG_PIN 8
#define ECHO_PIN 9
#define MOTOR1_IN1 4
#define MOTOR1_IN2 5
#define MOTOR2_IN3 6
#define MOTOR2_IN4 7
#define F_LED 13
#define B_LED 12
#define L_LED 11
#define R_LED 10
#define SERVO_PIN 3

Servo servo;

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(MOTOR1_IN1, OUTPUT);
    pinMode(MOTOR1_IN2, OUTPUT);
    pinMode(MOTOR2_IN3, OUTPUT);
    pinMode(MOTOR2_IN4, OUTPUT);
    digitalWrite(F_LED, OUTPUT);
    digitalWrite(B_LED, OUTPUT);
    digitalWrite(L_LED, OUTPUT);
    digitalWrite(R_LED, OUTPUT);

    servo.attach(SERVO_PIN);
    Serial.begin(9600);
}

long getDistance() {
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    return pulseIn(ECHO_PIN, HIGH) * 0.034 / 2;
}

void moveForward() {
    digitalWrite(MOTOR1_IN1, HIGH);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR2_IN3, HIGH);
    digitalWrite(MOTOR2_IN4, LOW);
    digitalWrite(F_LED, HIGH);

}

void turnRight() {
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, HIGH);
    digitalWrite(MOTOR2_IN3, HIGH);
    digitalWrite(MOTOR2_IN4, LOW);
    digitalWrite(R_LED, HIGH);

}

void turnLeft() {
    digitalWrite(MOTOR1_IN1, HIGH);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR2_IN3, LOW);
    digitalWrite(MOTOR2_IN4, HIGH);
    digitalWrite(L_LED, HIGH);

}

void stopCar() {
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR2_IN3, LOW);
    digitalWrite(MOTOR2_IN4, LOW);
    digitalWrite(F_LED, LOW);
    digitalWrite(R_LED, LOW);
    digitalWrite(L_LED, LOW);

}

void loop() {
    servo.write(90);
    delay(500);
    long distance = getDistance();
    Serial.print("Distance: ");
    Serial.println(distance);
    
    if (distance > 20) {
        moveForward();
    } else {
        stopCar();
        delay(500);
        servo.write(0);
        delay(500);
        long rightDist = getDistance();
        
        servo.write(180);
        delay(500);
        long leftDist = getDistance();
        
        if (rightDist > leftDist) {
            turnRight();
        } else {
            turnLeft();
        }
        delay(700);
    }
}