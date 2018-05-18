#include <ArduinoJson.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiAP.h>
#include <ESP8266WiFiGeneric.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFiScan.h>
#include <ESP8266WiFiSTA.h>
#include <ESP8266WiFiType.h>
#include <WiFiClient.h>
#include <WiFiClientSecure.h>
#include <WiFiServer.h>
#include <WiFiServerSecure.h>
#include <WiFiUdp.h>

void setup() {
  Serial.begin(9600);
  WiFi.begin("Home ZTE","Shift5771");

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("Waiting for connection");
    }
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("WiFi is connected");
    }

}

void loop() {
  if(WiFi.status() == WL_CONNECTED){
//    Serial.println("WiFi connected");
    }

}
