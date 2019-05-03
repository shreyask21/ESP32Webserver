/*
 * ESP32 Webserver with SPIFFS and WiFi AP mode
 * By Shreyas K
 */

#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"

const char* ssid = "ESP32_WebServer"; //Webserver AP SSID
const char* password = "password"; //Webserver AP Password
const int ledPin = 2;
#define PasswordProtectAP true //Comment out if you do not want password for AP.

AsyncWebServer server(80); //Start Async Webserver on port 80.

void setup() {
  pinMode(ledPin, OUTPUT);
  #ifdef PasswordProtectAP
  WiFi.softAP(ssid, password); //Use password protected AP
  #else
  WiFi.softAP(ssid); //Use open AP
  #endif
  
  SPIFFS.begin(); //Begin the SPIFFS
  server.begin(); //Begin Webserver

  
   // If register page is requested, read it from SPIFFS and send it as MIME type.
  server.on("/", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/index.html","text/html");
  });
  
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest * request) {
    request->send(SPIFFS, "/style.css", "text/css");
  });
  
  server.on("/on", HTTP_GET, [](AsyncWebServerRequest * request) {
    digitalWrite(ledPin, HIGH);
    request->send(SPIFFS, "/index.html","text/html");
  });
  
  server.on("/off", HTTP_GET, [](AsyncWebServerRequest * request) {
    digitalWrite(ledPin, LOW);
    request->send(SPIFFS, "/index.html","text/html");
  });
}
void loop() {
}
