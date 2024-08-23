//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
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

  // Inicializa o SoftwareSerial para o módulo GPS
  gpsSerial.begin(9600);
}
int seconds = 0;


void loop()
{
    while(gpsSerial.available()){
    char c = gpsSerial.read();
    if (gps.encode(c)){
      Serial.println(c);
    }
  }
}



