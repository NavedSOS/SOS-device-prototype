int buttonPin = 2;   // button connected to pin 2
int buzzerPin = 3;   // buzzer connected to pin 3

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); 
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) { // button pressed
    digitalWrite(buzzerPin, HIGH);    // turn buzzer ON
    delay(5000);                      // keep it ON for 5 sec
    digitalWrite(buzzerPin, LOW);     // then OFF
    // later we’ll also call sendSOS() here
  }
}
