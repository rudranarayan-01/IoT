# Hand Gesture Recognition with OpenCV, MediaPipe, and Arduino

## Overview
This project tracks hand gestures using **OpenCV** and **MediaPipe** and sends finger states to an **Arduino** via serial communication. The system detects whether each finger is up or down and transmits the data, which can be used to control devices like LEDs, motors, or robotic arms.

## Features
- Real-time **hand tracking** using a webcam.
- **Finger detection** (Thumb, Index, Middle, Ring, Pinky).
- **Serial communication** with an Arduino.
- Data transmission of finger states for external hardware control.

## Dependencies
Ensure you have the following Python libraries installed:

```bash
pip install opencv-python mediapipe pyserial
```

## Hardware Requirements
- **Webcam** (for hand tracking)
- **Arduino** (connected via USB)
- Any external **hardware** (LEDs, motors, etc.) for gesture-based control

## Setup and Installation
1. **Connect Arduino** to your computer.
2. **Upload Arduino Sketch** (if required for controlling hardware).
3. **Run the Python script**:

```bash
python hand_tracking.py
```

## Code Breakdown
### 1. **Initialize Serial Communication**
```python
arduino = serial.Serial(port='COM5', baudrate=9600, timeout=1)
time.sleep(2)  # Allow time for connection
```
- Sets up communication with Arduino on `COM5`.
- Adjust the `port` according to your system.

### 2. **Hand Tracking with MediaPipe**
```python
mp_hands = mp.solutions.hands
hands = mp_hands.Hands()
mp_drawing = mp.solutions.drawing_utils
```
- Loads MediaPipe’s **hand tracking** module.

### 3. **Detect Finger Positions**
```python
def detect_fingers(image, hand_landmarks):
    finger_tips = [8, 12, 16, 20]  # Index, Middle, Ring, Pinky
    thumb_tip = 4
    finger_states = [0, 0, 0, 0, 0]  # Thumb, Index, Middle, Ring, Pinky

    if hand_landmarks.landmark[thumb_tip].x < hand_landmarks.landmark[thumb_tip - 1].x:
        finger_states[0] = 1  # Thumb is up

    for idx, tip in enumerate(finger_tips):
        if hand_landmarks.landmark[tip].y < hand_landmarks.landmark[tip - 2].y:
            finger_states[idx + 1] = 1  # Other fingers are up

    return finger_states
```
- Determines whether each finger is **up (1)** or **down (0)**.

### 4. **Capture Video & Process Hand Data**
```python
cap = cv2.VideoCapture(0)
while cap.isOpened():
    success, image = cap.read()
    if not success:
        break

    image = cv2.cvtColor(cv2.flip(image, 1), cv2.COLOR_BGR2RGB)
    results = hands.process(image)
    image = cv2.cvtColor(image, cv2.COLOR_RGB2BGR)
```
- Captures **live video** from the webcam.
- Flips, processes, and converts image format.

### 5. **Send Data to Arduino**
```python
if results.multi_hand_landmarks:
    for hand_landmarks in results.multi_hand_landmarks:
        mp_drawing.draw_landmarks(image, hand_landmarks, mp_hands.HAND_CONNECTIONS)
        fingers_state = detect_fingers(image, hand_landmarks)
        arduino.write(bytes(fingers_state))
        print(f"Fingers State: {fingers_state}")
```
- Detects fingers and **sends data** to Arduino via serial communication.

### 6. **Display Live Tracking & Close Resources**
```python
cv2.imshow('Hand Tracking', image)
if cv2.waitKey(5) & 0xFF == 27:
    break

cap.release()
cv2.destroyAllWindows()
arduino.close()
```
- Displays the **live feed** with detected hand landmarks.
- **Exits** when the `Esc` key is pressed.
- Releases camera and closes connections.

## Example Output
```
Fingers State: [0, 1, 1, 0, 0]
Fingers State: [1, 1, 1, 1, 1]
Fingers State: [0, 0, 0, 0, 0]
```

## Possible Applications
- **Control LEDs** with finger gestures.
- **Move a robotic arm**.
- **Sign language recognition**.
- **Gaming & VR interactions**.

## Notes
- Modify `COM5` to match your Arduino port.
- Arduino should be programmed to **read the received bytes** and act accordingly.

## License
This project is open-source and free to use under the **MIT License**.


## Contributors
- **Name** - Rudranarayan Sahu
- **Email** - rudranarayansahu.tech@gmail.com

---
### 🔹 **Want Help with Arduino Code?**
Let me know if you need an Arduino script to **process the received gestures**! 🚀

## Contact
For any queries or contributions, contact **rudranarayansahu.tech@gmail.com** or visit **[GitHub](https://github.com/rudranarayan-01)**.

Happy Coding✨✨
Have a nice day ✨✨
