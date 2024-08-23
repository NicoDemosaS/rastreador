#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

const int rxPin = 2; // Pino digital 2 para RX
const int txPin = 3; // Pino digital 3 para TX

SoftwareSerial gpsSerial(rxPin, txPin); // Cria um objeto SoftwareSerial
TinyGPSPlus gps;

void setup()
{
  Serial.begin(9600);
  Serial.println("Serial NODEMCU iniciado a 9600");
  gpsSerial.begin(9600);
  Serial.println("Serial GPS iniciado a 9600");
}

void loop()
{
  while (gpsSerial.available())
  {
    Serial.println("Gps available");
    char info = gpsSerial.read();
    if (gps.encode(info))
    {
      Serial.println(info);
    }
  }
}