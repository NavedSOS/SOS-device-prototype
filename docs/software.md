# Software Plan for SOS Device

## 1. Firmware (Device Code)
- Runs on ESP32 microcontroller.
- Continuously checks if SOS button is pressed.
- When pressed:
  - but firstly: if it's pressed  unconsciously so it'll send notification to their parents they'll check it and by using the app they'll turn off the sos signal,, but incase even the parents didn't pay attention then it'll buz after 5-10 min to remind them if it's true or not 
  - Collects GPS coordinates.
  - Sends SOS alert via GSM/4G to server.
  - Gives feedback to user (vibration or LED blink).

## 2. Mobile App
- Connects to server to show location of SOS device.
- Parents/Guardians can log in and see:
  - Real-time GPS map
  - SOS history
  - Battery status of device

## 3. Server/Backend
- Stores SOS alerts in a secure database.
- Sends notifications (SMS, push, or email) to parents.
- Can generate reports (e.g., frequency of alerts, last location).

## 4. Future Add-ons
- AI-based anomaly detection (detect unusual movement).
- Voice-based SOS (microphone trigger).
- Offline mode (device sends SMS even without internet).
