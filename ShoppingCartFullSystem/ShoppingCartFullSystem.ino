//API headers
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
//API headers end

//RFID headers
#include <stdio.h>
#include <string.h>
//RFID header end

//RFID global variables
char id[100];
char data[5];
int val =0;
String items[50];
int itemNo=0;
//RFID global variables end


void setup() {
  //magnet and buzzer
  pinMode(D1,OUTPUT);//for magnet
  pinMode(D2,OUTPUT);//for buzzer
  //magnet and buzzer end
  
//WiFi setup
Serial.begin(9600);
  WiFi.begin("OnePlus X","shift5771");

  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("Waiting for connection");
    }
  if(WiFi.status() == WL_CONNECTED){
    Serial.println("WiFi is connected");
    }
//WiFi setup end

//  RFID setup
  //Serial.begin(9600);
  delay(500);
  //Serial.flush();
  Serial.println();
  Serial.println("Waiting for RFID tag.... ");
// RFID setup end

}

void loop() {
  bool TorF = false;
  val = Serial.read();
  while(! Serial.available()){
    Serial.print("..");
    val = Serial.read(); 
    delay(1000);    
    }

  Serial.read();
  Serial.read();
  Serial.read();
  Serial.read();
  data[0] = Serial.read();
  data[1] = Serial.read();
  data[2] = Serial.read();
  data[3] = Serial.read();
  data[4] = Serial.read();
  data[5]=Serial.read();
  Serial.read();
  Serial.read();
  Serial.read();

  memcpy(id, data, 7);
  id[7] = '\0'; 
  //Serial.println('\0');
  
  TorF = id_check(id, items);
  
  
  if(!TorF){
    Serial.println("Item detected");
    items[itemNo]=id;
    itemNo++;

    //Sending json object to server
    if(WiFi.status() == WL_CONNECTED){
    StaticJsonBuffer<300> JSONbuffer;
    JsonObject& JSONencoder = JSONbuffer.createObject();

    JSONencoder["name"] = id;
    JSONencoder["price"] = "790";

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

    //buzzer and magnet activation
    digitalWrite(D2,HIGH);
    delay(3000);
    digitalWrite(D2,LOW);
    digitalWrite(D1,HIGH);
    delay(8000);
    digitalWrite(D1,LOW);
    }

    //activate magnate & buzzer
    }

   else{
    Serial.println("Alrady entered item");
    }
  Serial.println(items[itemNo]);
  
  //Serial.println(sizeof(items)/sizeof(items[0]));
  
  
  //delay(3000);
}

bool id_check(char* id, String* items){
  int i=0;
  while(items[i]!='\0'){
    if(items[i]==id){
      return true;
      }
    else{
      i=i+1;
      }

    
    }
    return false;
 
  
  }
