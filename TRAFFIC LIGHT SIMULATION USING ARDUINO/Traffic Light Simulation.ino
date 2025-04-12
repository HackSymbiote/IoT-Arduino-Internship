int red = 2;
int yellow = 4;
int green = 6; // [cite: 235]

void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  digitalWrite(red, HIGH); // Turn on Red LED [cite: 236]
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(1500); // Wait for 1.5 seconds [cite: 236]

  digitalWrite(red, LOW);
  digitalWrite(yellow, HIGH); // Turn on Yellow LED [cite: 237]
  digitalWrite(green, LOW);
  delay(1500);

  digitalWrite(red, LOW); // Turn on Green LED [cite: 237]
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH); // [cite: 238]
  delay(1500);
}