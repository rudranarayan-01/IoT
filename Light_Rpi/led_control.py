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