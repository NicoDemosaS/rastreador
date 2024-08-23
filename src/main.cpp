#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

const int rxPin = 2; // Pino digital 2 para RX
const int txPin = D3; // Pino digital 3 para TX

SoftwareSerial gpsSerial(4, 5); // Cria um objeto SoftwareSerial
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
  while (gpsSerial.available() > 0)
  {
  delay(2500);
  gps.encode(gpsSerial.read());
    {
      Serial.print("Latitude: ");
      Serial.println(gps.location.lat(), 6);
      Serial.print("Longetude ");
      Serial.println(gps.location.lng(), 6);
      Serial.print("Altitude: ");
      Serial.println(gps.altitude.meters());
      Serial.print("Horario em minuto: ");
      Serial.println(gps.time.minute());
      Serial.print("Velocidade em KM/h: ");
      Serial.println(gps.speed.kmph());
      Serial.print("Quantidade Satelites: ");
      Serial.println(gps.satellites.value());

    }
  }
}

// Documentacao
// https://arduiniana.org/libraries/tinygpsplus/