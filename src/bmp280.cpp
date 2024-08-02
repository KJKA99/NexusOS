/*#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP280.h>

// Define the SPI pins
#define BMP_SCK 18
#define BMP_MISO 16
#define BMP_MOSI 17
#define BMP_CS 8

// Create an instance of the BMP280 class using SPI
//Adafruit_BMP280 bmp; // I2C
Adafruit_BMP280 bmp(BMP_CS); // hardware SPI
// Adafruit_BMP280 bmp(BMP_CS, BMP_MOSI, BMP_MISO, BMP_SCK); // software SPI

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    delay(100); // Wait for native USB
  }

  Serial.println("Starting setup...");
  
  Serial.println("BMP280 test");
  unsigned status = bmp.begin();

  if (!status) {
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    Serial.print("SensorID was: 0x"); 
    Serial.println(bmp.sensorID(), 16);
    Serial.print("        ID of 0xFF probably means a bad address, a BMP 180 or BMP 085\n");
    Serial.print("   ID of 0x56-0x58 represents a BMP 280,\n");
    Serial.print("        ID of 0x60 represents a BME 280.\n");
    Serial.print("        ID of 0x61 represents a BME 680.\n");
    while (1) {
      delay(10); // Halt if sensor not found
    }
  }

  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     // Operating Mode. 
                  Adafruit_BMP280::SAMPLING_X2,     // Temp. oversampling 
                  Adafruit_BMP280::SAMPLING_X16,    // Pressure oversampling 
                  Adafruit_BMP280::FILTER_X16,      // Filtering. 
                  Adafruit_BMP280::STANDBY_MS_500); // Standby time.
}

void loop() {
  Serial.println("Looping...");

  Serial.print(F("Temperature = "));
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");

  Serial.print(F("Pressure = "));
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");

  Serial.print(F("Approx altitude = "));
  Serial.print(bmp.readAltitude(1013.25)); // Adjusted to local forecast! 
  Serial.println(" m");

  Serial.println();
  delay(2000);
}
*/