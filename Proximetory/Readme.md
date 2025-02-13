# HC-SR04 Ultrasonic Distance Sensor with Buzzer, LED, and Arduino

## Overview
This project demonstrates how to use the **HC-SR04 Ultrasonic Distance Sensor** with an **Arduino**, **Buzzer**, and **LED** to create a simple **proximity alert system**. When an object comes within a specified distance (20 cm), the **LED lights up** and the **buzzer sounds an alarm**.

## Components Required
- **Arduino Uno** (or compatible board)
- **HC-SR04 Ultrasonic Sensor**
- **Buzzer**
- **LED**
- **Resistor (220Ω for LED)**
- **Jumper Wires**
- **Breadboard**

## Circuit Diagram
| **Component** | **Pin** | **Arduino Pin** |
|--------------|--------|---------------|
| **HC-SR04** | VCC    | 5V            |
|             | GND    | GND           |
|             | TRIG   | D9            |
|             | ECHO   | D10           |
| **Buzzer**  | +      | D6            |
|             | -      | GND           |
| **LED**     | +      | D5 (through 220Ω resistor) |
|             | -      | GND           |

## Arduino Code
```cpp
#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 5
#define BUZZER_PIN 6

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
```

## Explanation
1. The **HC-SR04 ultrasonic sensor** emits an ultrasonic pulse and measures the time it takes to return.
2. Distance is calculated using:
   ```
   Distance = (Time * 0.034) / 2
   ```
3. If the measured distance is **less than or equal to 20 cm**, the **LED turns on** and the **buzzer sounds**.
4. If the object is **farther than 20 cm**, both the **LED and buzzer turn off**.

## Applications
- **Obstacle detection systems**
- **Security alarms**
- **Smart parking systems**
- **Automated distance-based alerts**

## Setup Instructions
1. **Connect the components** as per the circuit diagram.
2. **Upload the provided Arduino code** using the **Arduino IDE**.
3. **Power up the Arduino**, and observe the LED and buzzer responding to detected objects.

## Customization
- Modify the **distance threshold** (change `if (distance <= 20)`) to suit your needs.
- Adjust the **buzzer frequency** (`tone(BUZZER_PIN, 1000)`) to change the sound.
- Add an **LCD display** to show the distance.

## License
This project is open-source and can be modified or distributed freely.

## Author
Developed by Rudranarayan Sahu

---
**Happy Coding! 🚀**

