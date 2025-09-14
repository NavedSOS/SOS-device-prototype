#include <SoftwareSerial.h>

// --- Pins ---
int buttonPin = 2;
int buzzerPin = 3;

// --- GSM Module ---
SoftwareSerial sim800(7, 8); // RX, TX

// --- GPS Module ---
SoftwareSerial gps(4, 5);    // RX, TX

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);

  Serial.begin(9600);
  sim800.begin(9600);
  gps.begin(9600);

  Serial.println("SOS Device Ready...");
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    triggerSOS();
  }
}

void triggerSOS() {
  // Step 1: buzzer ON
  digitalWrite(buzzerPin, HIGH);
  delay(2000);
  digitalWrite(buzzerPin, LOW);

  // Step 2: get location (dummy for now)
  String latitude = "28.7041";
  String longitude = "77.1025";
  String locationURL = "https://maps.google.com/?q=" + latitude + "," + longitude;

  // Step 3: send SMS
  sendSMS(locationURL);

  delay(10000); // wait 10 seconds before allowing another alert
}

void sendSMS(String location) {
  sim800.println("AT+CMGF=1"); // text mode
  delay(500);
  sim800.println("AT+CMGS=\"+911234567890\""); // replace with parent’s number
  delay(500);
  sim800.print("SOS ALERT! Need help. Location: ");
  sim800.println(location);
  delay(500);
  sim800.write(26); // Ctrl+Z to send
  delay(1000);

  Serial.println("SOS Alert Sent: " + location);
}
