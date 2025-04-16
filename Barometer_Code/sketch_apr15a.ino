#include <Adafruit_MPL3115A2.h>
#include <Wire.h>

Adafruit_MPL3115A2 baro;

void setup() {
  Serial.begin(115200);
  while (!Serial);  // Wait for serial monitor

  if (!baro.begin()) {
    Serial.println("Could not find sensor");
    while (1);
  }
}

void loop() {
  float pressure = baro.readPressure();
  float altitude = baro.readAltitude();
  float temp = baro.readTemp();

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" Pa");

  Serial.print("Altitude: ");
  Serial.print(altitude);
  Serial.println(" meters");

  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  delay(1000);
}
