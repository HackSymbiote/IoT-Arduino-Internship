const int ledPins[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, A0}; // [cite: 250]
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]); // [cite: 251]

void setup() {
  for (int i = 0; i < numLeds; i++) { // [cite: 252]
    pinMode(ledPins[i], OUTPUT); // [cite: 252]
  } // [cite: 253]
}

void loop() {
  // Forward chase
  for (int i = 0; i < numLeds; i++) { // [cite: 253]
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  } // [cite: 254]

  // Reverse chase
  for (int i = numLeds - 1; i >= 0; i--) { // [cite: 254]
    digitalWrite(ledPins[i], HIGH);
    delay(100);
    digitalWrite(ledPins[i], LOW);
  } // [cite: 255]
}