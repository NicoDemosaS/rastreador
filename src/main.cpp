#include <Arduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#include <ESP8266WiFi.h> 
#include <ESP8266HTTPClient.h>


// >> Acredito que nao esta sendo utilizado tambem.
const int rxPin = D2; // Pino digital 2 para RX
const int txPin = D3; // Pino digital 3 para TX

#define URL "http://192.168.1.111:8000/rastreio/"

#define WLAN_SSID  "xxxxxx"   // nome da sua rede
#define WLAN_PASS  "xxxxxx"   // senha de acesso do seu roteador

// Client Para requisiçoes Wifi
WiFiClient client;


// >> Acredito que seja desnecessario o SoftwareSerial
SoftwareSerial gpsSerial(4, 5); // Cria um objeto SoftwareSerial

TinyGPSPlus gps;

void httpRequest(float lat, float lng, float alt, float min, float kmp, int sat){

  // Conexao Wifi
  if (WiFi.status() == WL_CONNECTED){

    HTTPClient http;
    	

  // Header e Link para HTTP request
  http.begin(client , URL);
  http.addHeader("Content-Type", "application/json");


  // Json Payload meio obvio ne
  String jsonPayload ="{\"lat\":" + String(lat) + 
           ",\"lng\":" + String(lng) + 
           ",\"alt\":" + String(alt) + 
           ",\"min\":" + String(min) + 
           ",\"kmp\":" + String(kmp) + 
           ",\"sat\":" + String(sat) + 
           "}";


  int httpCode = http.POST(jsonPayload);

  // Se a pagina responder algo, ele pega e mostra no terminal.
  if (httpCode >0)
  {
    String payload = http.getString();
    Serial.println(payload);
  }

  http.end();

  }
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Serial NODEMCU iniciado a 9600");
  gpsSerial.begin(9600);
  Serial.println("Serial GPS iniciado a 9600");

  // Conexao Wifi
  WiFi.mode(WIFI_STA); //Habilita o modo estação
  WiFi.begin(WLAN_SSID, WLAN_PASS); // Login na rede WiFi 
  Serial.print("Conectando");

  while (WiFi.status() != WL_CONNECTED) // Espera ate estabelecer conexao
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
   while (gpsSerial.available() > 0)
   {
   delay(2500);
   gps.encode(gpsSerial.read());
     {
       float lat = gps.location.lat();
       float lng = gps.location.lng();
       float alt = gps.altitude.meters();
       float min = gps.time.minute();
       float kmp = gps.speed.kmph();
       int sat = gps.satellites.value();

      if (lat == 0)
      {
      httpRequest(lat, lng, alt, min, kmp, sat);
      delay(45000);
      }
      else
      {
        httpRequest(lat, lng, alt, min, kmp, sat);
        delay(15000);
      }


     }
   }
}








// Documentacao do GPS
// https://arduiniana.org/libraries/tinygpsplus/