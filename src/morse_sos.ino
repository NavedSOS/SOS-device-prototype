// morse_sos.ino
// Blink SOS in Morse code (... --- ...)

int ledPin = 13; // built-in LED

void setup() {
  pinMode(ledPin, OUTPUT);
}

// Function to blink dot (short blink)
void dot() {
  digitalWrite(ledPin, HIGH);
  delay(200); // short on
  digitalWrite(ledPin, LOW);
  delay(200); // gap
}

// Function to blink dash (long blink)
void dash() {
  digitalWrite(ledPin, HIGH);
  delay(600); // long on
  digitalWrite(ledPin, LOW);
  delay(200); // gap
}

void loop() {
  // S = dot dot dot
  dot(); dot(); dot();
  delay(600); // letter gap

  // O = dash dash dash
  dash(); dash(); dash();
  delay(600); // letter gap

  // S = dot dot dot
  dot(); dot(); dot();
  delay(2000); // word gap before repeating
}
