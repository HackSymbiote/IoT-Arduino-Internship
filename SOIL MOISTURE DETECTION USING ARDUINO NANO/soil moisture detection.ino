

// Define the analog pin connected to the sensor's output
const int sensorPin = A0;

// Variables to store sensor values
int sensorValue = 0;       // Stores the raw analog reading
int moisturePercentage = 0; // Stores the mapped percentage

// Define the typical range for mapping (adjust based on calibration)
// These values might need adjustment. Test your sensor!
// Value in air (or very dry soil)
const int dryValue = 950; // Example value, adjust based on your sensor reading in air/dry soil
// Value when fully submerged in water
const int wetValue = 400; // Example value, adjust based on your sensor reading in water

void setup() {
  // Initialize Serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Soil Moisture Sensor Reading");
  Serial.println("---------------------------");
}

void loop() {
  // Read the analog value from the sensor:
  sensorValue = analogRead(sensorPin);

  // Print the raw sensor value (0-1023):
  Serial.print("Raw Sensor Value: ");
  Serial.print(sensorValue);

  // Map the sensor value to a percentage (0-100%)
  // Note: Lower raw values usually mean higher moisture.
  // We use constrain to keep the value within the defined dry/wet range before mapping.
  // Then map it so wetValue corresponds to 100% and dryValue corresponds to 0%.
  moisturePercentage = map(sensorValue, wetValue, dryValue, 100, 0);

  // Ensure the percentage stays within 0-100% bounds, especially if sensorValue goes outside the calibrated range
   if (moisturePercentage < 0) {
    moisturePercentage = 0;
  }
  if (moisturePercentage > 100) {
    moisturePercentage = 100;
  }


  // Print the calculated moisture percentage:
  Serial.print(" | Moisture Percentage: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  // Wait for a short period before taking the next reading
  delay(1000); // Delay of 1 second (1000 milliseconds)
}
