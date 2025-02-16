# Raspberry Pi LED On/Off Project

## Overview
This project demonstrates how to control an LED using a Raspberry Pi 3B+ and Python. The LED will turn on and off at one-second intervals using a simple script written in Python.

## Hardware Requirements
- Raspberry Pi 3B+
- LED (Any color)
- 330Ω Resistor
- Breadboard
- Jumper Wires

## Circuit Connections
1. Connect the **long leg (anode)** of the LED to **GPIO 17** (Pin 11) on the Raspberry Pi.
2. Connect the **short leg (cathode)** of the LED to one side of a **330Ω resistor**.
3. Connect the **other side of the resistor** to **GND (Pin 6)** on the Raspberry Pi.

## Software Requirements
- Raspbian OS (or any compatible OS)
- Python 3
- Ginny Programming Editor (or any other Python editor)
- RPi.GPIO Library (Pre-installed on Raspbian OS)

## Installation & Setup
1. Open **Ginny Programming Editor** on your Raspberry Pi.
2. Create a new Python script (`led_control.py`).
3. Copy and paste the following code:

```python
import RPi.GPIO as GPIO
import time

# Set GPIO mode
GPIO.setmode(GPIO.BCM)
LED_PIN = 17  # GPIO pin where LED is connected

# Set LED_PIN as an output
GPIO.setup(LED_PIN, GPIO.OUT)

try:
    while True:
        GPIO.output(LED_PIN, GPIO.HIGH)  # Turn LED on
        print("LED ON")
        time.sleep(1)  # Wait for 1 second

        GPIO.output(LED_PIN, GPIO.LOW)   # Turn LED off
        print("LED OFF")
        time.sleep(1)  # Wait for 1 second

except KeyboardInterrupt:
    GPIO.cleanup()  # Cleanup GPIO on exit
    print("\nGPIO Cleaned up. Exiting...")
```

4. Save the file as `led_control.py`.
5. Open a terminal and run the script:
   ```sh
   python3 led_control.py
   ```

## How It Works
- The script sets **GPIO 17** as an output.
- It continuously turns the LED on and off every second.
- Press **Ctrl + C** to stop the script, and it will clean up GPIO settings before exiting.

## Troubleshooting
- Ensure all connections are correct and the GPIO pin number matches the script.
- If the script does not run, install the **RPi.GPIO** library using:
  ```sh
  sudo apt-get install python3-rpi.gpio
  ```
- Use `GPIO.cleanup()` if the GPIO pins become unresponsive after an error.

## License
This project is open-source and free to use for educational purposes.

## Author
Developed by **Rudranarayan Sahu**
**Email** - rudranarayansahu.tech@gmail.com

Feel free to connect ✨✨ Happy Coding..!!
