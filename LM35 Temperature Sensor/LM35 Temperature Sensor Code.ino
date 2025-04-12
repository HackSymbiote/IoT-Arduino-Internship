#define sensorPin A1

void setup() {
  Serial.begin(9600);
}

void loop() {
  int reading = analogRead(sensorPin);
  float voltage = reading * (5.0 / 1024.0);  // [cite: 138]
  float temperatureC = voltage * 100;       // [cite: 138]
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print("\xC2\xB0"); // shows degree symbol [cite: 139]
  Serial.print("C | ");

  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0; // [cite: 139]
  Serial.print(temperatureF);
  Serial.print("\xC2\xB0"); // shows degree symbol [cite: 140]
  Serial.println("F");

  delay(1000); // wait a second between readings [cite: 140]
}