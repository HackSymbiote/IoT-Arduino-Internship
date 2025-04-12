#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define PIRPIN 3

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature and Human Body Sensor Test"); // [cite: 188]
  dht.begin();
  pinMode(PIRPIN, INPUT);
}

void loop() {
  float temperature = dht.readTemperature(); // [cite: 188]

  if (isnan(temperature)) { // [cite: 189]
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  int motionDetected = digitalRead(PIRPIN); // [cite: 189]
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C"); // [cite: 189]

  if (motionDetected == HIGH) { // [cite: 190]
    Serial.println("Motion detected: Human presence detected!");
  } else {
    Serial.println("Motion detected: No human presence.");
  }

  delay(2000); // [cite: 190]
}