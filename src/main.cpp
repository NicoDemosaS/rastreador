#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <ESP8266WiFi.h> 

const int rxPin = 2; // Pino digital 2 para RX
const int txPin = D3; // Pino digital 3 para TX



#define WLAN_SSID   "NOME DO WIFI"   // nome da sua rede
#define WLAN_PASS  "SENHA"   // senha de acesso do seu roteador

// Client Para requisiçoes Wifi
WiFiClient client;

SoftwareSerial gpsSerial(4, 5); // Cria um objeto SoftwareSerial
TinyGPSPlus gps;

void setup()
{
  Serial.begin(9600);
  Serial.println("Serial NODEMCU iniciado a 9600");
  gpsSerial.begin(9600);
  Serial.println("Serial GPS iniciado a 9600");

  // Conexao Wifi
  WiFi.mode(WIFI_STA); //Habilita o modo estação
  WiFi.begin(WLAN_SSID, WLAN_PASS); //Inicia WiFi com os dados preenchidos 
  Serial.print("Conectando"); 
  while (WiFi.status() != WL_CONNECTED) // Tentando conectar na Rede WiFi
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println(WiFi.localIP());
}

void loop()
{


  // Mensagens Filtradas do GPS
  // while (gpsSerial.available() > 0)
  // {
  // delay(2500);
  // gps.encode(gpsSerial.read());
  //   {
  //     Serial.print("Latitude: ");
  //     Serial.println(gps.location.lat(), 6);
  //     Serial.print("Longetude ");
  //     Serial.println(gps.location.lng(), 6);
  //     Serial.print("Altitude: ");
  //     Serial.println(gps.altitude.meters());
  //     Serial.print("Horario em minuto: ");
  //     Serial.println(gps.time.minute());
  //     Serial.print("Velocidade em KM/h: ");
  //     Serial.println(gps.speed.kmph());
  //     Serial.print("Quantidade Satelites: ");
  //     Serial.println(gps.satellites.value());

  //   }
  // }
}

// Documentacao
// https://arduiniana.org/libraries/tinygpsplus/

