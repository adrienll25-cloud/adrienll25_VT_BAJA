#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 4   // ESP32 GPIO4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println("ESP32 DS18B20 Temperature Sensor");
  sensors.begin();

  Serial.print("Sensors detected: ");
  Serial.println(sensors.getDeviceCount());
}

void loop() {

  sensors.requestTemperatures();

  float tempC = sensors.getTempCByIndex(0);

  if (tempC == DEVICE_DISCONNECTED_C) {
    Serial.println("Sensor not detected");
  }
  else {
    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.println(" C");
  }

  delay(1000);
}