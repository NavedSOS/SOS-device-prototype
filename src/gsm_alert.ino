#include <SoftwareSerial.h>

SoftwareSerial sim800(7, 8); // RX, TX

void setup() {
  sim800.begin(9600);
  Serial.begin(9600);

  delay(1000);
  Serial.println("GSM Module ready...");

  // Send an SOS alert
  sendSOS();
}

void loop() {
  // nothing here for now
}

void sendSOS() {
  sim800.println("AT+CMGF=1"); // Set SMS to text mode
  delay(500);
  sim800.println("AT+CMGS=\"+911234567890\""); // Replace with parent's number
  delay(500);
  sim800.println("SOS ALERT! Need help. Location: https://maps.google.com/?q=28.7041,77.1025"); 
  delay(500);
  sim800.write(26); // End SMS with Ctrl+Z
  delay(1000);
}
