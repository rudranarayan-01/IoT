
# Gas Sensor Alarm System

This project is an Arduino-based gas detection system that uses an analog gas sensor to monitor air quality. When gas concentration exceeds a predefined threshold, the system triggers a buzzer alarm and changes the color of an RGB LED to indicate the danger level.

## Components Required
- Arduino board (Uno, Mega, or compatible)
- Gas sensor (e.g., MQ-2, MQ-135, or similar)
- RGB LED
- Buzzer
- Jumper wires
- Resistors (if needed for LED)

## Circuit Connections
### **Gas Sensor:**
- `VCC` → `5V`
- `GND` → `GND`
- `A0` → `A0` (Analog input)

### **Buzzer:**
- Positive → `D2`
- Negative → `GND`

### **RGB LED:**
- Red Pin → `D5`
- Green Pin → `D6`
- Common cathode/anode as per LED type

## Code Explanation
1. **Reading Sensor Data:**
   - The gas sensor's analog value is read from `A0`.
   - This value is printed to the Serial Monitor for debugging.

2. **Triggering Alerts:**
   - If `sensorValue > 300`:
     - The buzzer sounds an alarm (`500 Hz` for `300ms`).
     - The RGB LED turns **red** (indicating danger).
   - Otherwise:
     - The buzzer remains off.
     - The RGB LED turns **green** (indicating safety).

3. **Serial Monitor Output:**
   - Displays real-time gas sensor readings for monitoring.

## Code
```cpp
const int sensorPin = A0;
int sensorValue;

const int buzzerPin = 2;
const int RPin = 5;
const int GPin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(RPin, OUTPUT);
  pinMode(GPin, OUTPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.print("Analog output: ");
  Serial.println(sensorValue);

  if (sensorValue > 300) {
    tone(buzzerPin, 500, 300);
    digitalWrite(GPin, LOW);
    digitalWrite(RPin, HIGH);
  } else {
    noTone(buzzerPin);
    digitalWrite(RPin, LOW);
    digitalWrite(GPin, HIGH);
  }
  delay(50);
}
```

## Possible Improvements
- Add a **dynamic threshold** using a potentiometer or serial input.
- Implement **multiple alert levels** (e.g., yellow for moderate danger, red for high danger).
- Use an **OLED display** to show real-time sensor values instead of the Serial Monitor.

## How to Use
1. Connect the components as per the circuit diagram.
2. Upload the provided Arduino sketch to your board.
3. Open the **Serial Monitor** (`9600 baud rate`) to view real-time gas sensor values.
4. Observe the LED and buzzer behavior based on gas concentration.

## License
This project is open-source. Feel free to modify and enhance it.

---
**Created for educational purposes and experimental use.** 🚀

