// SOS Device Prototype
// Basic Arduino setup for SOS button + buzzer

int buttonPin = 2;     // Push button on pin 2
int buzzerPin = 8;     // Buzzer on pin 8
int ledPin = 13;       // On-board LED

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {  
    // Button pressed
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(ledPin, HIGH);
    Serial.println("🚨 SOS Activated!");
  } else {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(ledPin, LOW);
  }
}
