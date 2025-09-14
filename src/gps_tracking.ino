// gps_tracking.ino
// Example code to read GPS coordinates

#include <SoftwareSerial.h>

// RX = pin 4, TX = pin 3
SoftwareSerial gpsSerial(4, 3);

void setup() {
  Serial.begin(9600);      // Arduino serial monitor
  gpsSerial.begin(9600);   // GPS module baud rate
  Serial.println("GPS Module Test Started...");
}

void loop() {
  while (gpsSerial.available() > 0) {
    char gpsData = gpsSerial.read();
    Serial.print(gpsData);  // Print GPS raw data
  }
}
