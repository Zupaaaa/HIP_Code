void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
#include <ModbusMaster.h>

ModbusMaster node;

void setup() {
  // Start the Serial Monitor at 9600 baud
  Serial.begin(9600);
  
  // Initialize Modbus communication at slave address 1
  node.begin(1, Serial); // 1 is the Modbus slave address
}

void loop() {
  uint8_t result;
  
  // Request data from the sensor (adjust registers as needed)
  result = node.readInputRegisters(0x00, 2); // Read two input registers starting from address 0x00
  
  if (result == node.ku8MBSuccess) {
    // If the request is successful, read the data from the response buffer
    uint16_t rawValue = node.getResponseBuffer(0);
    
    // Convert the raw data to a more useful value (e.g., irradiance)
    float voltage = (rawValue / 65535.0) * 5.0;  // Assuming the sensor outputs 0-5V
    float irradiance = (voltage / 5.0) * 2000.0;  // Adjust the conversion factor as needed

    // Print the irradiance value to the Serial Monitor
    Serial.print("Solar Irradiance: ");
    Serial.print(irradiance);
    Serial.println(" W/m²");
  } else {
    // Print error if the Modbus request failed
    Serial.println("Failed to read data.");
  }

  // Wait for a second before requesting data again
  delay(1000);
}
}
