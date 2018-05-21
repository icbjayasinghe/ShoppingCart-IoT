#include <stdio.h>
#include <string.h>

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


char id[100];
char data[5];
char itemList[50];
int val =0;//still not much use
int itemNo=0;


void setup() {
  Serial.begin(9600);
  delay(500);
  
  Serial.flush();
  Serial.println();
  Serial.println("Waiting for RFID tag.... ");

}

void loop() {

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
  Serial.println(id);
  
  delay(3000);
}

bool id_check(char id){
  
  }
