#include <ESP8266HTTPClient.h>

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
    StaticJsonBuffer<300> JSONbuffer;
    JsonObject& JSONencoder = JSONbuffer.createObject();

    JSONencoder["name"] = "denim";
    JSONencoder["price"] = "2000";

    char JSONmessageBuffer[300];
    JSONencoder.prettyPrintTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
    Serial.println(JSONmessageBuffer);

    HTTPClient http;
    http.begin("http://35.229.49.95:8080/api/v1/productItem");
    http.addHeader("Content-Type", "application/json");
    int httpCode = http.POST(JSONmessageBuffer);
    String payload = http.getString();
    Serial.println(httpCode);
    Serial.println(payload);
    http.end();

    delay(120000);
        
    }

}
