// blink.ino
// First Arduino program - Blink LED

void setup() {
  pinMode(13, OUTPUT);   // Pin 13 = Built-in LED
}

void loop() {
  digitalWrite(13, HIGH); // LED ON
  delay(1000);            // wait 1 second
  digitalWrite(13, LOW);  // LED OFF
  delay(1000);            // wait 1 second
}
