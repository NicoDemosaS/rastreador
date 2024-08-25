#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h>

const int rxPin = D2; // Pino digital 2 para RX
const int txPin = D3; // Pino digital 3 para TX

int lat = 3020;
int lng = 2030;

#define WLAN_SSID  "MERCUSYS_FB85"   // nome da sua rede
#define WLAN_PASS  "11009528"   // senha de acesso do seu roteador

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
  if (WiFi.status() == WL_CONNECTED){

    HTTPClient http;
    	
  http.begin(client ,"http://192.168.1.111:8000/rastreio/");
  http.addHeader("Content-Type", "application/json");



  String jsonPayload = "{\"lat\":" + String(lat) + ",\"lng\":" + String(lng) + "}";

  int httpCode = http.POST(jsonPayload);

  if (httpCode >0)
  {
    String payload = http.getString();
    Serial.println(payload);
  }

  http.end();

  }

  delay(5000);


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

// Documentacao do GPS
// https://arduiniana.org/libraries/tinygpsplus/